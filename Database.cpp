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

// void Database::sortBySalary();

void Database::sortByLastName()
{
    std::sort(begin(data), end(data), [] (Person * left, Person * right)
            {
                return left->getLastName() < right->getLastName();
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
//void Database::removeByPersonalID(const unsigned long personalID);
//void Database::modifySalary(const unsigned long personalID);
//void Database::modifyAdress(const unsigned long personalID);
//bool Database::validatePersonalID(const unsigned long personalID);

