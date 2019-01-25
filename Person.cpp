#include "Person.hpp"


Person::Person(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress)
    : firstName_(firstName),
    lastName_(lastName),
    personalID_(personalID),
    gender_(gender),
    adress_(adress)
{}

std::string Person::getLastName() const
{
    return lastName_;
}

int32_t Person::getPersonalID()const
{
    return personalID_;
}

Employee::Employee(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress,
                const int salaries)
    : Person(firstName, lastName, personalID, gender, adress),
    salaries_(salaries)
{}

Student::Student(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress,
                const int studentID)
    : Person(firstName, lastName, personalID, gender, adress),
    studentID_(studentID)
{}
