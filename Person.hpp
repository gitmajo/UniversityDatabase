#pragma once
#include <string>
#include <iostream>

class Person
{
    //enum gender{male, female};
    
    protected:
        std::string firstName_;
        std::string lastName_;
        int64_t personalID_;
        bool gender_;
        std::string adress_;
    
    public:
        Person(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress);

        virtual ~Person() {};
        virtual int getData() const
        {
            return personalID_;
        }
        std::string getLastName() const;
        int32_t getPersonalID() const;
};

class Employee : public Person
{ 
        int salaries_;
    public:
        Employee(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress,
                const int salaries);
};

class Student : public Person
{
    private:
        int32_t studentID_;
        
    public:
        Student(const std::string firstName,
                const std::string lastName,
                const int64_t personalID,
                const bool gender,     
                const std::string adress,
                const int studentID);

        int getData() const
        {
            return studentID_;
        };
};
