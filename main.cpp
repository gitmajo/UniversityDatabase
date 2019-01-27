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
    
    db.addStudent("Kubus",  "Puchatek",  91653426865, 1, "Las",     11111);
    db.addStudent("Tomasz", "Kowalski",  87654237541, 1, "Wroclaw", 22222);
    db.addStudent("Kasia",  "Nowak",     64247643211, 0, "Opole",   34568);
    db.addEmployee("Jan",   "Szymczak",  87235681241, 1, "Wroclaw", 54674);
    db.addEmployee("Aldona", "Tomczyk",  65321543987, 0, "Lublin",  43211);
    db.addStudent("Stanislaw", "Olech",  90764357981, 1, "Lublin",  65421);
    
    db.printDatabase();

    return 0;
}
