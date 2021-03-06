#include "Person.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

Person::Person(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const Gender& gender,
        const std::string& address)
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
        << std::left << std::setw(8) << convMap_.at(gender_)  << " "
        << std::left << std::setw(13) << address_  << "\n";

    return ss.str();
}

double Person::getSalary() const
{
    return std::nan("");
}

unsigned long Person::getStudentIndex() const
{
    return 0;
}

void Person::setAddress(const std::string& newAddress)
{
    address_ = newAddress;
}

void Person::setSalary(const double& /*salary*/) { }
