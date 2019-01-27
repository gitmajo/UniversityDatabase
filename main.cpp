#include <iostream>
#include "Person.hpp"
#include "Database.hpp"

std::ostream& operator<<(std::ostream& os, Person* person)
{
          os << person->getInfo();
          return os;
}


int main()
{
    std::cout << "Hello on master!\n\n";
    
    Database db;
    
    db.addStudent("Kubus",  "Puchatek",  91653426865, 1, "Las",     111111);
    db.addStudent("Tomasz", "Kowalski",  87654237541, 1, "Wroclaw", 122222);
    db.addStudent("Kasia",  "Nowak",     64247643211, 0, "Opole",   334568);
    db.addEmployee("Jan",   "Szymczak",  87235681241, 1, "Wroclaw", 3674);
    db.addEmployee("Aldona", "Tomczyk",  65321543987, 0, "Lublin",  2211);
    db.addStudent("Stanislaw", "Olech",  90764357981, 1, "Lublin",  265421);
    
    db.printDatabase();

    std::cout << "sortBySalary():\n";
    db.sortBySalary();
    db.printDatabase();

    std::cout << "sortByLastName():\n";
    db.sortByLastName();
    db.printDatabase();



    return 0;
}
