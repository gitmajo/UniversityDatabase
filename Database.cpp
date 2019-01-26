#include "Database.hpp"
#include <algorithm>

//void searchByLastName();
//void searchByPersonalID();

void Database::printDatabase() const
{
    for(const auto& person : data)
        std::cout << person;
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

void Database::addPerson(Person * person)
{
    data.push_back(person);
}

//void Database::loadFromFile();
//void Database::saveToFile();

void Database::removeByPersonalID(const unsigned long personalID)
{
    auto iter = std::find_if(begin(data), end(data), [personalID](Person * person){return person->getPersonalID()==personalID;});
    if (iter != end(data))
    {
        data.erase(iter);
    }
}

//void Database::modifySalary(const unsigned long personalID);
//void Database::modifyAdress(const unsigned long personalID);
//bool Database::validatePersonalID(const unsigned long personalID);

