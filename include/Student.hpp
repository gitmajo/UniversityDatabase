#pragma once
#include "Person.hpp"

class Student : public Person
{
    private:
        unsigned long studentIndex_;

    public:
        Student(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const Gender& gender,
                const std::string& address,
                const unsigned long& studentIndex);

        unsigned long getStudentIndex() const;
        std::string getInfo() const;
};
