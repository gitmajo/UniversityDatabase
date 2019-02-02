#include "Employee.hpp"
#include <sstream>
#include <iomanip>

Employee::Employee(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const bool& gender,
        const std::string& address,
        const double& salary)
: Person(firstName, lastName, personalID, gender, address),
    salary_(salary)
{}

double Employee::getSalary() const
{
    return salary_;
}

void Employee::setSalary(const double& salary)
{
    salary_ = salary;
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
