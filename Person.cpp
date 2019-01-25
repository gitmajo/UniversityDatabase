#include "Person.hpp"


Person::Person(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
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

unsigned long Person::getPersonalID()const
{
    return personalID_;
}

Employee::Employee(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
                const bool gender,     
                const std::string adress,
                const double salary)
    : Person(firstName, lastName, personalID, gender, adress),
    salary_(salary)
{}

double Employee::getSalary() const
{
    return salary_;
}

Student::Student(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
                const bool gender,     
                const std::string adress,
                const unsigned long studentIndex)
    : Person(firstName, lastName, personalID, gender, adress),
    studentIndex_(studentIndex)
{}

unsigned long Student::getStudentIndex() const
{
    return studentIndex_;
}
