#pragma once
#include <iostream>
#include <string>

class Person
{
    protected:
        std::string firstName_;
        std::string lastName_;
        unsigned long long personalID_;
        bool gender_;
        std::string address_;

    public:
        Person(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const bool& gender,
                const std::string& address);


        std::string getLastName() const;
        unsigned long long getPersonalID() const;
        void setAddress(const std::string& newAddress);
        
        friend std::ostream& operator<<(std::ostream& os, const Person* person);
        virtual std::string getInfo() const;
        virtual ~Person() {};
};

