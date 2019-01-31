#pragma once
#include "Person.hpp"

class Employee : public Person
{ 
    private:
        double salary_;
    public:
        Employee(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const bool& gender,
                const std::string& address,
                const double& salary);

        double getSalary() const;
        void setSalary(const double& salary);
        std::string getInfo() const;

};

