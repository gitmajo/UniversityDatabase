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

void Database::sortByStudentID()
{
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {
                Student* student1 = dynamic_cast<Student*>(left);
                Student* student2 = dynamic_cast<Student*>(right);
                return student1 -> getStudentIndex() < student2 -> getStudentIndex();
            });
}

void Database::addPerson(Person* person)
{
    data.push_back(person);
}

bool Database::addStudent(const std::string firstName, 
        const std::string lastName,
        const unsigned long long personalID,
        const bool gender,
        const std::string address,
        const unsigned long studentIndex)
{
    Person* student = new Student(firstName, lastName, personalID,
            gender, address, studentIndex);
    addPerson(student);
    return true;
}

bool Database::addEmployee(const std::string firstName, 
        const std::string lastName,
        const unsigned long long personalID,
        const bool gender,
        const std::string address,
        const double salary)
{
    Person* employee = new Employee(firstName, lastName, personalID,
            gender, address, salary);
    addPerson(employee);
    return true;
}


//void Database::loadFromFile();
//void Database::saveToFile();

bool Database::removeByPersonalID(const unsigned long long personalID)
{
    auto iter = std::find_if(begin(data), end(data), [personalID](Person* person){return person->getPersonalID()==personalID;});
    if (iter != end(data))
    {
        data.erase(iter);
    }
}

//void Database::modifySalary(const unsigned long personalID);
//void Database::modifyAdress(const unsigned long personalID);
//bool Database::validatePersonalID(const unsigned long personalID);

