#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "Person.hpp"

class Database
{
    private:
        std::vector<Person*> data;
    public:
        void searchByLastName();
        void searchByPersonalID();
        void printDatabase() const;
        void sortBySalary();
        void sortByLastName();
        void sortByStudentID();
        void addPerson(Person* person);

        bool addStudent(const std::string firstName, 
                const std::string lastName,
                const unsigned long long personalID,
                const bool gender,
                const std::string address,
                const unsigned long studentIndex);

        bool addEmployee(const std::string firstName,
                const std::string lastName,
                const unsigned long long personalID,
                const bool gender,
                const std::string address,
                const double salary);

        void loadFromFile();
        void saveToFile();
        bool removeByPersonalID(const unsigned long long personalID);
        void modifySalary(const unsigned long long personalID);
        void modifyAdress(const unsigned long long personalID);
        bool validatePersonalID(const unsigned long long personalID);
};

