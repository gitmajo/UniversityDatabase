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
        std::vector<Person> data;
    public:
        void printDatabase() const;
        bool addStudent() const; 
        bool addEmployee() const;

};

