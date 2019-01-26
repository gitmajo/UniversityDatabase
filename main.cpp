#include <iostream>
#include "Person.hpp"
#include "Database.hpp"

std::ostream& operator<<(std::ostream& os, const Person& person)
{
        os << std::left << std::setw(13) << person.lastName_   << " "
           << std::left << std::setw(13) << person.firstName_  << " "
           << std::left << std::setw(13) << person.personalID_ << " "
           << std::left << std::setw(13) << person.gender_  << " "
           << std::left << std::setw(13) << person.address_  << "\n";
            return os;
}


int main()
{
    std::cout << "Hello on master!\n";

    return 0;
}
