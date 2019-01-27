#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Person
{
    //enum gender{male, female};
    
    protected:
        std::string firstName_;
        std::string lastName_;
        unsigned long long personalID_;
        bool gender_;
        std::string address_;
    
    public:
        Person(const std::string firstName,
                const std::string lastName,
                const unsigned long long personalID,
                const bool gender,     
                const std::string address);

        
        std::string getLastName() const;
        unsigned long long getPersonalID() const;
        friend std::ostream& operator<<(std::ostream& os, Person* person);

        virtual std::string getInfo();
        virtual ~Person() {};
        
        
};

class Employee : public Person
{ 
    private:
        double salary_;
    public:
        Employee(const std::string firstName,
                const std::string lastName,
                const unsigned long long personalID,
                const bool gender,     
                const std::string address,
                const double salary);

        double getSalary() const;
        std::string getInfo();
        
};

class Student : public Person
{
    private:
        unsigned long studentIndex_;
        
    public:
        Student(const std::string firstName,
                const std::string lastName,
                const unsigned long long personalID,
                const bool gender,     
                const std::string address,
                const unsigned long studentIndex);

        unsigned long getStudentIndex() const;
        std::string getInfo();
};
