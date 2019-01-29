#include <iostream>
#include <vector>

bool checkPersonalID(const unsigned long long& personalID);
bool initialIdCheck(const unsigned long long& personalID);
void splitNumberIntoDigits(std::vector<int>& digits, unsigned long long number);
bool checkDay(std::vector<int>& digits, const unsigned long long& personalID);
bool checkcontrolSum(std::vector<int>& digits, const unsigned long long& personalID);

int main(){
    std::cout << "check PersonalID!\n";

    unsigned long long a = 44051401358;
    unsigned long long b = 81100216357;
    unsigned long long c = 81100216353;
    unsigned long long d = 65071209862;
    unsigned long long e = 12076509862;


    std::cout << a << ": " << checkPersonalID(a) << "\n";
    std::cout << b << ": " << checkPersonalID(b) << "\n";
    std::cout << c << ": " << checkPersonalID(c) << "\n";
    std::cout << d << ": " << checkPersonalID(d) << "\n";
    std::cout << e << ": " << checkPersonalID(e) << "\n";

    return 0;
}

bool initialIdCheck(std::vector<int>& digits, const unsigned long long& personalID)
{    
    const int personalIdLength = 11;
    splitNumberIntoDigits(digits, personalID);

    if(personalID < 0 or digits.size() != personalIdLength) 
        return false;

    return true;
}

bool checkDay(std::vector<int>& digits, const unsigned long long& personalID)
{
    int day = digits[4]*10 + digits[5];
    if(day >= 1 and day <= 31)
        return true;

    return false;
}

bool checkPersonalID(const unsigned long long& personalID){    
    std::vector<int> digits {}; 

    std::cout << "a";
    if( !initialIdCheck(digits, personalID)) return false;

    std::cout << "b";
    if( !checkDay(digits, personalID)) return false;

    std::cout << "c";
    if( !checkcontrolSum(digits, personalID)) return false;
    std::cout << "d";

    return true;
}

bool checkcontrolSum(std::vector<int>& digits, const unsigned long long& personalID)
{
    unsigned long int sum = 0;
    const std::vector<int> multipliers {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    for(int i=0; i<digits.size(); i++)
        sum += (digits[i] * multipliers[i]);

    if(sum % 10 == 0) 
        return true;

    return false;
}

void splitNumberIntoDigits(std::vector<int>& digits, unsigned long long number)
{
    int digit = 0;
    while(number > 0)
    {
        digit = number % 10;
        number /= 10;
        digits.insert(digits.begin(), digit);
    }
}
