#include "PersonalID.hpp"

namespace
{
    bool initialIdCheck(std::vector<int>& digits, const unsigned long long& personalID);
    void splitNumberIntoDigits(std::vector<int>& digits, unsigned long long number);
    bool checkDay(std::vector<int>& digits);
    bool checkControlSum(std::vector<int>& digits);
}

namespace ValidatePersonalID
{
    bool validatePersonalID(const unsigned long long& personalID)
    {    
        std::vector<int> digits {}; 

        if( !initialIdCheck(digits, personalID)) return false;
        if( !checkDay(digits)) return false;
        if( !checkControlSum(digits)) return false;

        return true;
    } 

    void test()
    {
        unsigned long long a = 44051401358;
        unsigned long long b = 81100216357;
        unsigned long long c = 81100216353;
        unsigned long long d = 65071209862;
        unsigned long long e = 12076509862;

        std::cout << a << ": " << validatePersonalID(a) << "\n";
        std::cout << b << ": " << validatePersonalID(b) << "\n";
        std::cout << c << ": " << validatePersonalID(c) << "\n";
        std::cout << d << ": " << validatePersonalID(d) << "\n";
        std::cout << e << ": " << validatePersonalID(e) << "\n";
    }  
}

namespace
{
    bool initialIdCheck(std::vector<int>& digits, const unsigned long long& personalID)
    {    
        const int personalIdLength = 11;
        splitNumberIntoDigits(digits, personalID);

        if(digits.size() != personalIdLength) 
            return false;

        return true;
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

    bool checkDay(std::vector<int>& digits)
    {
        int day = digits[4]*10 + digits[5];
        if(day >= 1 and day <= 31)
            return true;

        return false;
    }

    bool checkControlSum(std::vector<int>& digits)
    {
        unsigned long int sum = 0;
        const std::vector<int> multipliers {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
        for(unsigned int i=0; i<digits.size(); i++)
            sum += (digits[i] * multipliers[i]);

        if(sum % 10 == 0) 
            return true;

        return false;
    }
}

