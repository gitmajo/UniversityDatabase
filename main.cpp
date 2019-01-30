#include <iostream>
#include "Person.hpp"
#include "Database.hpp"

std::ostream& operator<<(std::ostream& os, const Person* person)
{
    os << person->getInfo();
    return os;
}


int main()
{
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

    std::cout << "sortByPersonalID():\n";
    db.sortByPersonalID();
    db.printDatabase();

    std::cout << "Searching for Puchatek:\n";
    db.searchByLastName("Puchatek");

    std::cout << "Searching for ID 87235681241:\n";
    db.searchByPersonalID(87235681241);

    std::cout << "Searching for index 334568:\n";
    db.searchByStudentID(334568);
    db.removeByStudentID(334568);
    std::cout << "removeByStudentID(334568):\n";
    db.printDatabase();

    std::cout << "sortByStudentID():\n";
    db.sortByStudentID();
    db.printDatabase();

    db.saveToFile();

    Database temp;
    temp.printDatabase();

    temp.loadFromFile();
    temp.printDatabase();
    
    std::cout << "validatePersonalID():\n";
    vpid::test();

    std::cout << "Searching for ID 87235681241:\n";
    db.searchByPersonalID(87235681241);
 
    std::cout << "modifyAddress(87235681241, Kalisz):\n";
    db.modifyAddress(87235681241, "Kalisz");
    db.searchByPersonalID(87235681241);

    std::cout << "modifyAddress(invalid, Kalisz):\n";
    db.modifyAddress(87235681240, "Kalisz");
    
    std::cout << "modifySalary(87235681241, 3333):\n";
    db.modifySalary(87235681241, 3333);
    db.searchByPersonalID(87235681241);

    std::cout << "modifySalary(invalid, 3333):\n";
    db.modifySalary(87235681240, 3333);

    std::cout << "modifySalary(student, 3333):\n";
    db.modifySalary(91653426865, 3333);


    

    return 0;
}
