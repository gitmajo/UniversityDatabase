#include "Person.hpp"


Person::Person(const std::string firstName,
        const std::string lastName,
        const unsigned long long personalID,
        const bool gender,     
        const std::string address)
: firstName_(firstName),
    lastName_(lastName),
    personalID_(personalID),
    gender_(gender),
    address_(address)
{}

std::string Person::getLastName() const
{
    return lastName_;
}

unsigned long long Person::getPersonalID() const
{
    return personalID_;
}

std::string Person::getInfo() const
{
    auto ss = std::stringstream{};
    ss << std::left << std::setw(13) << lastName_   << " "
        << std::left << std::setw(13) << firstName_  << " "
        << std::left << std::setw(13) << personalID_ << " "
        << std::left << std::setw(13) << gender_  << " "
        << std::left << std::setw(13) << address_  << "\n";

    return ss.str();
}


Employee::Employee(const std::string firstName,
        const std::string lastName,
        const unsigned long long personalID,
        const bool gender,     
        const std::string address,
        const double salary)
: Person(firstName, lastName, personalID, gender, address),
    salary_(salary)
{}

double Employee::getSalary() const
{
    return salary_;
}

std::string Employee::getInfo() const
{
    auto ss = std::stringstream{};

    ss << std::left << std::setw(13) << lastName_   << " "
        << std::left << std::setw(13) << firstName_  << " "
        << std::left << std::setw(13) << personalID_ << " "
        << std::left << std::setw(13) << gender_  << " "
        << std::left << std::setw(13) << address_  << " "
        << std::left << std::setw(13) << salary_  << " "
        << std::left << std::setw(13) << "----"  << "\n"; 

    return ss.str();

}

Student::Student(const std::string firstName,
        const std::string lastName,
        const unsigned long long personalID,
        const bool gender,     
        const std::string address,
        const unsigned long studentIndex)
: Person(firstName, lastName, personalID, gender, address),
    studentIndex_(studentIndex)
{}

double Student::getSalary() const
{
    return std::nan("");
}

unsigned long Student::getStudentIndex() const
{
    return studentIndex_;
}

std::string Student::getInfo() const
{
    auto ss = std::stringstream{};

    ss << std::left << std::setw(13) << lastName_   << " "
        << std::left << std::setw(13) << firstName_  << " "
        << std::left << std::setw(13) << personalID_ << " "
        << std::left << std::setw(13) << gender_  << " "
        << std::left << std::setw(13) << address_  << " "
        << std::left << std::setw(13) << "----"  << " " 
        << std::left << std::setw(13) << studentIndex_  << "\n";

    return ss.str();
}
