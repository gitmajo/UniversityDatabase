#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

#include "Person.hpp"
#include "PersonalID.hpp"

using personIter = std::vector<Person*>::iterator;

class Database
{
    private:
        std::vector<Person*> data;
    public:
        personIter searchByLastName(const std::string& lastName);
        personIter searchByPersonalID(const unsigned long long& personalID);
        personIter searchByStudentID(const unsigned long& studentID);
        void printDatabase() const;
        void sortBySalary();
        void sortByLastName();
        void sortByStudentID();
        void addPerson(Person* person);

        bool addStudent(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const bool& gender,
                const std::string& address,
                const unsigned long& studentIndex);

        bool addEmployee(const std::string& firstName,
                const std::string& lastName,
                const unsigned long long& personalID,
                const bool& gender,
                const std::string& address,
                const double& salary);

        bool loadFromFile(const std::string filename = "../database.txt");
        bool saveToFile(const std::string filename = "../database.txt");
        bool removeByPersonalID(const unsigned long long& personalID);
        bool removeByStudentID(const unsigned long& studentID);
        bool modifySalary(const unsigned long long& personalID, const double& newSalary);
        bool modifyAddress(const unsigned long long& personalID, const std::string& address);
};
