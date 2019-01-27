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

std::string Person::getInfo()
{
    return "person";
}
//{
/*        os << std::left << std::setw(13) << person.lastName_   << " "
           << std::left << std::setw(13) << person.firstName_  << " "
           << std::left << std::setw(13) << person.personalID_ << " "
           << std::left << std::setw(13) << person.gender_  << " "
           << std::left << std::setw(13) << person.address_  << "\n";
            return os;
*/
//}


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

std::string Employee::getInfo()
{
    return "employee";
/*        os << std::left << std::setw(13) << person.lastName_   << " "
           << std::left << std::setw(13) << person.firstName_  << " "
           << std::left << std::setw(13) << person.personalID_ << " "
           << std::left << std::setw(13) << person.gender_  << " "
           << std::left << std::setw(13) << person.address_  << " "
           << std::left << std::setw(13) << person.salary_  << " "
           << std::left << std::setw(13) << "----"  << "\n"; 
            return os;
*/
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

unsigned long Student::getStudentIndex() const
{
    return studentIndex_;
}

std::string Student::getInfo()
{
    return "student";
/*        os << std::left << std::setw(13) << person.lastName_   << " "
           << std::left << std::setw(13) << person.firstName_  << " "
           << std::left << std::setw(13) << person.personalID_ << " "
           << std::left << std::setw(13) << person.gender_  << " "
           << std::left << std::setw(13) << person.address_  << " "
           << std::left << std::setw(13) << "----"  << " " 
           << std::left << std::setw(13) << person.studentIndex_  << "\n";
            return os;
*/

}
