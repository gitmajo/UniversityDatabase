#include "Database.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using studentPtr = std::shared_ptr<Student>;
using employeePtr = std::shared_ptr<Employee>;

personIter Database::searchByLastName(const std::string& lastName)
{
    auto it = std::find_if(begin(data_), end(data_), [lastName] (personPtr person)
            {
                return person->getLastName() == lastName;
            });

    if (it != end(data_))
        std::cout << *it << "\n";
    else
        std::cout << "Person " << lastName << " not found\n\n";
    return it;
}

personIter Database::searchByPersonalID(const unsigned long long& personalID)
{
    auto it = std::find_if(begin(data_), end(data_), [personalID] (personPtr person)
            {
                return person->getPersonalID() == personalID;
            });

    if (it != end(data_))
        std::cout << *it << "\n";
    else
        std::cout << "Personal ID " << personalID << " not found.\n\n";
    return it;
}

personIter Database::searchByStudentID(const unsigned long& studentID)
{
    auto it = std::find_if(begin(data_), end(data_), [studentID] (personPtr person)
            {
                return person->getStudentIndex() == studentID;
            });

    if (it != end(data_))
        std::cout << *it << "\n";
    else
        std::cout << "Student ID " << studentID << " not found.\n\n";
    return it;
}

void Database::printDatabase() const
{
    if(data_.empty())
        std::cout << "Empty data_base!\n";

    for(const auto& personPtr : data_)
        std::cout << personPtr;
    std::cout << "\n";
}

void Database::sortBySalary()
{
    std::sort(begin(data_), end(data_), [](personPtr left, personPtr right)
            {   //input: 10.1 Nan 2.5  Nan 3.6    //output: 2.5 3.6 10.1 Nan Nan
                
                //NaN 2.5 --- if NaN on the left: bad!
                if (std::isnan(left->getSalary())) return false;

                //2.5 NaN -- if NaN on the right: good!
                if (std::isnan(right->getSalary())) return true;

                //left and right are finite, so compare it usually
                return left->getSalary() < right->getSalary();
            });
}

void Database::sortByLastName()
{
    std::sort(begin(data_), end(data_), [](personPtr left, personPtr right)
            {
                return left->getLastName() < right->getLastName();
            });
}

void Database::sortByPersonalID()
{
    std::sort(begin(data_), end(data_), [](personPtr left, personPtr right)
            {
                return left->getPersonalID() < right->getPersonalID();
            });
}

void Database::sortByStudentID()
{
    std::sort(begin(data_), end(data_), [](personPtr left, personPtr right)
            {
                return left->getStudentIndex() < right->getStudentIndex();
            });
}

void Database::addPerson(personPtr person)
{
    data_.push_back(person);
}

bool Database::addStudent(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const Gender& gender,
        const std::string& address,
        const unsigned long& studentIndex)
{
    personPtr student = std::make_shared<Student>(firstName,
            lastName, personalID, gender, address, studentIndex);
    addPerson(student);
    return true;
}

bool Database::addEmployee(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const Gender& gender,
        const std::string& address,
        const double& salary)
{
    personPtr employee = std::make_shared<Employee>(firstName,
            lastName, personalID, gender, address, salary);
    addPerson(employee);
    return true;
}

bool Database::loadFromFile(const std::string filename/*="database.txt"*/)
{
    std::ifstream ifs {filename}; //input file stream
    if(!ifs)
    {
        std::cout << "Could not open " << filename << " for reading!\n";
        return false;
    }
    return parseLineByLine(ifs);
}

bool Database::parseLineByLine(std::ifstream& ifs)
{
    std::string firstName, lastName, address, salary, studentIndex;
    unsigned long long personalID;
    char cGender;
    std::map<char, Gender> convMap {{'0', Gender::female}, {'1', Gender::male}};

    while(ifs >> lastName >> firstName >> personalID >> cGender >>
            address >> salary >> studentIndex)
    {
        if(salary == "----")
            addStudent(firstName, lastName, personalID, convMap[cGender], address, std::stoul(studentIndex));
        else if(studentIndex == "----")
            addEmployee(firstName, lastName, personalID, convMap[cGender], address, std::stod(salary));
        else
        {
            std::cout << "\nInvalid line in input file!\n";
            return false;
        }
    }
    return true;
}

bool Database::saveToFile(const std::string filename/*="database.txt"*/)
{
    std::ofstream ofs {filename}; //output file stream

    if(!ofs)
    {
        std::cout << "Could not open " << filename << " for writing!\n";
        return false;
    }
    return writeLineByLine(ofs);
}

bool Database::writeLineByLine(std::ofstream& ofs)
{
    for(const auto& personPtr : data_)
        ofs << personPtr;
    ofs << "\n";
    return true;
}

bool Database::removeByPersonalID(const unsigned long long& personalID)
{
    auto iter = searchByPersonalID(personalID);

    if (iter != end(data_))
    {
        data_.erase(iter);
        return true;
    }
    else
        return false;
}

bool Database::removeByStudentID(const unsigned long& studentID)
{
    auto iter = searchByStudentID(studentID);

    if (iter != end(data_))
    {
        data_.erase(iter);
        return true;
    }
    else
        return false;
}

bool Database::modifySalary(const unsigned long long& personalID, const double& newSalary)
{
    auto personIter = searchByPersonalID(personalID);

    if (personIter != data_.end())
    {
        if(std::isfinite((*personIter)->getSalary()))
        {
            (*personIter)->setSalary(newSalary);
            return true;
        }
        std::cout << "Personal ID " << personalID << " is not an Employee.\n\n";
    }
    return false;
}

bool Database::modifyAddress(const unsigned long long& personalID, const std::string& newAddress)
{
    auto personIter = searchByPersonalID(personalID);

    if (personIter != data_.end())
    {    
        (*personIter)->setAddress(newAddress);
        return true;
    }
    return false;
}
