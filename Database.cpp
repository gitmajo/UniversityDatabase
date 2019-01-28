#include "Database.hpp"
#include <algorithm>

//void searchByLastName();
//void searchByPersonalID();

void Database::printDatabase() const
{
    for(const auto& personPtr : data)
        std::cout << personPtr;
    std::cout << "\n";
}

void Database::sortBySalary()
{
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {   
            //input: 10.1 Nan 2.5  Nan 3.6 
            //output: 2.5 3.6 10.1 Nan Nan

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
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {
            return left->getLastName() < right->getLastName();
            });
}

void Database::addPerson(Person* person)
{
    data.push_back(person);
}

bool Database::addStudent(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const bool& gender,
        const std::string& address,
        const unsigned long& studentIndex)
{
    Person* student = new Student(firstName, lastName, personalID,
            gender, address, studentIndex);
    addPerson(student);
    return true;
}

bool Database::addEmployee(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const bool& gender,
        const std::string& address,
        const double& salary)
{
    Person* employee = new Employee(firstName, lastName, personalID,
            gender, address, salary);
    addPerson(employee);
    return true;
}


bool Database::loadFromFile(const std::string filename/*="database.txt"*/)
{
    std::ifstream ifs {filename}; //input file stream
    if(!ifs){
        std::cout << "Could not open " << filename << " for reading!\n";
        return false;
    }

    std::string firstName, lastName, address, salary, studentIndex;
    unsigned long long personalID;
    bool gender;

    while(ifs >> lastName >> firstName >> personalID >> gender >>
            address >> salary >> studentIndex)
    {
        if(salary == "----")
            addStudent(firstName, lastName, personalID, gender, address, std::stold(studentIndex));
        else if(studentIndex == "----")
            addEmployee(firstName, lastName, personalID, gender, address, std::stod(salary));
        else{
            std::cout << "\nInvalid line in input file!\n";
            return false;
        }
    }

    return true;
}

bool Database::saveToFile(const std::string filename/*="database.txt"*/)
{
    std::ofstream ofs {filename}; //output file stream

    if(!ofs){
        std::cout << "Could not open " << filename << " for writing!\n";
        return false;
    }
    for(const auto& personPtr : data)
        ofs << personPtr;
    ofs << "\n";
    return true;
}


//void Database::removeByPersonalID(const unsigned long personalID);
//void Database::modifySalary(const unsigned long personalID);
//void Database::modifyAdress(const unsigned long personalID);
//bool Database::validatePersonalID(const unsigned long personalID);

