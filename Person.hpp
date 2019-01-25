#pragma once
#include <string>
#include <iostream>

class Person
{
    //enum gender{male, female};
    
    protected:
        std::string firstName_;
        std::string lastName_;
        unsigned long personalID_;
        bool gender_;
        std::string adress_;
    
    public:
        Person(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
                const bool gender,     
                const std::string adress);

        virtual ~Person() {};
        std::string getLastName() const;
        unsigned long getPersonalID() const;
};

class Employee : public Person
{ 
    private:
        double salary_;
    public:
        Employee(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
                const bool gender,     
                const std::string adress,
                const double salary);

        double getSalary() const;
};

class Student : public Person
{
    private:
        unsigned long studentIndex_;
        
    public:
        Student(const std::string firstName,
                const std::string lastName,
                const unsigned long personalID,
                const bool gender,     
                const std::string adress,
                const unsigned long studentIndex);

        unsigned long getStudentIndex() const;
};
