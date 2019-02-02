#include "Student.hpp"
#include <sstream>
#include <iomanip>

Student::Student(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const Gender& gender,
        const std::string& address,
        const unsigned long& studentIndex)
: Person(firstName, lastName, personalID, gender, address),
    studentIndex_(studentIndex)
{}

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
        << std::left << std::setw(8) << convMap.at(gender_)  << " "
        << std::left << std::setw(13) << address_  << " "
        << std::left << std::setw(13) << "----"  << " " 
        << std::left << std::setw(13) << studentIndex_  << "\n";

    return ss.str();
}

