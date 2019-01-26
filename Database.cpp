#include "Database.hpp"

void Database::printDatabase() const
{
    for(const auto& person : data)
        std::cout << person;
    std::cout << "\n";
}
