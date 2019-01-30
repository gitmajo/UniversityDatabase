#include "Database.hpp"

personIter Database::searchByLastName(const std::string& lastName)
{
    std::vector<Person*>::iterator it = std::find_if(begin(data), end(data), [lastName] (Person* person) 
            {
            return person -> getLastName() == lastName;
            });

    if (it != end(data))
        std::cout << *it << "\n";
    else
        std::cout << "Person " << lastName << " not found\n\n";
    return it;
}

personIter Database::searchByPersonalID(const unsigned long long& personalID)
{
    std::vector<Person*>::iterator it = std::find_if(begin(data), end(data), [personalID] (Person* person) 
            {
            return person -> getPersonalID() == personalID;
            });

    if (it != end(data))
        std::cout << *it << "\n";
    else
        std::cout << "Personal ID " << personalID << " not found.\n\n";
    return it;
}

personIter Database::searchByStudentID(const unsigned long& studentID)
{
    std::vector<Person*>::iterator it = std::find_if(begin(data), end(data), [studentID] (Person* person) 
            {
            Student* student = dynamic_cast<Student*>(person);
            return student -> getStudentIndex() == studentID;
            });

    if (it != end(data))
        std::cout << *it << "\n";
    else
        std::cout << "Student ID " << studentID << " not found.\n\n";
    return it;
}

void Database::printDatabase() const
{
    if(data.empty())
        std::cout << "Empty database!\n";

    for(const auto& personPtr : data)
        std::cout << personPtr;
    std::cout << "\n";
}

void Database::sortBySalary()
{
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {
            //input: 10.1 NaN 2.5  NaN 3.6
            //output: 2.5 3.6 10.1 Nan Nan

            //NaN 2.5 --- if student on the left: bad!
            if(dynamic_cast<Student*>(left)) return false;

            //2.5 NaN -- if student on the right: good! move all to the right
            if(dynamic_cast<Student*>(right)) return true;

            Employee* e_left = dynamic_cast<Employee*>(left);
            Employee* e_right = dynamic_cast<Employee*>(right);
            //if employee, compare it usually
            return e_left->getSalary() < e_right->getSalary();
            });

}
void Database::sortByLastName()
{
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {
            return left->getLastName() < right->getLastName();
            });
}

void Database::sortByStudentID()
{
    std::sort(begin(data), end(data), [](Person* left, Person* right)
            {
            if(dynamic_cast<Employee*>(left)) return false;
            if(dynamic_cast<Employee*>(right)) return true;

            Student* student1 = dynamic_cast<Student*>(left);
            Student* student2 = dynamic_cast<Student*>(right);
            return student1->getStudentIndex() < student2->getStudentIndex();
            });
}

void Database::addPerson(Person* person)
{
    data.push_back(person);
}

bool Database::addStudent(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const bool& gender,
        const std::string& address,
        const unsigned long& studentIndex)
{
    Person* student = new Student(firstName, lastName, personalID,
            gender, address, studentIndex);
    addPerson(student);
    return true;
}

bool Database::addEmployee(const std::string& firstName,
        const std::string& lastName,
        const unsigned long long& personalID,
        const bool& gender,
        const std::string& address,
        const double& salary)
{
    Person* employee = new Employee(firstName, lastName, personalID,
            gender, address, salary);
    addPerson(employee);
    return true;
}


bool Database::loadFromFile(const std::string filename/*="database.txt"*/)
{
    std::ifstream ifs {filename}; //input file stream
    if(!ifs){
        std::cout << "Could not open " << filename << " for reading!\n";
        return false;
    }

    std::string firstName, lastName, address, salary, studentIndex;
    unsigned long long personalID;
    bool gender;

    while(ifs >> lastName >> firstName >> personalID >> gender >>
            address >> salary >> studentIndex)
    {
        if(salary == "----")
            addStudent(firstName, lastName, personalID, gender, address, std::stold(studentIndex));
        else if(studentIndex == "----")
            addEmployee(firstName, lastName, personalID, gender, address, std::stod(salary));
        else{
            std::cout << "\nInvalid line in input file!\n";
            return false;
        }
    }

    return true;
}

bool Database::saveToFile(const std::string filename/*="database.txt"*/)
{
    std::ofstream ofs {filename}; //output file stream

    if(!ofs){
        std::cout << "Could not open " << filename << " for writing!\n";
        return false;
    }
    for(const auto& personPtr : data)
        ofs << personPtr;
    ofs << "\n";
    return true;
}



bool Database::removeByPersonalID(const unsigned long long& personalID)
{
    auto iter = searchByPersonalID(personalID);

    if (iter != end(data))
    {
        data.erase(iter);
        return true;
    }
    else
        return false;
}

bool Database::removeByStudentID(const unsigned long& studentID)
{
    auto iter = searchByStudentID(studentID);

    if (iter != end(data))
     {
         data.erase(iter);
         return true;
     }
     else
         return false;
}

bool Database::modifySalary(const unsigned long long& personalID, const double& newSalary)
{
    auto personIter = searchByPersonalID(personalID);

    if (personIter != data.end())
    {
        if(Employee* isEmployee = dynamic_cast<Employee*>(*personIter))
        {
            isEmployee->setSalary(newSalary);
            return true;
        }
        std::cout << "Personal ID " << personalID << " is not an Employee.\n\n";
    }
    return false;
}


bool Database::modifyAddress(const unsigned long long& personalID, const std::string& newAddress)
{
    auto personIter = searchByPersonalID(personalID);

    if (personIter != data.end())
    {    
        (*personIter)->setAddress(newAddress);
        return true;
    }
    return false;
}


