#pragma once
#include <iostream>
#include <string>
#include <map>

enum class Gender {female, male};

class Person
{
    protected:
        std::string firstName_;
        std::string lastName_;
        unsigned long long personalID_;
        Gender gender_;
        std::string address_;
        std::map<Gender, char> convMap {{Gender::female, '0'}, {Gender::male, '1'}};

    public:
        Person(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const Gender& gender,
                const std::string& address);


        std::string getLastName() const;
        unsigned long long getPersonalID() const;
        void setAddress(const std::string& newAddress);

        friend std::ostream& operator<<(std::ostream& os, const Person* person);
        virtual std::string getInfo() const;
        virtual ~Person() {};
};

