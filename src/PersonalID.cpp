#include "PersonalID.hpp"
#include <iostream>
#include <vector>
#include <numeric>

namespace
{
    bool initialIdCheck(std::vector<int>& digits, const unsigned long long& personalID);
    void splitNumberIntoDigits(std::vector<int>& digits, unsigned long long number);
    bool checkFormatOfDate(std::vector<int>& digits);
    bool checkControlSum(std::vector<int>& digits);
}

namespace ValidatePersonalID
{
    bool validatePersonalID(const unsigned long long& personalID)
    {    
        std::vector<int> digits {}; 

        if( !initialIdCheck(digits, personalID)) return false;
        if( !checkFormatOfDate(digits)) return false;
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
        std::cout << e << ": " << validatePersonalID(e) << "\n\n";
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

    bool checkFormatOfDate(std::vector<int>& digits)
    {
        //check if yy-mm-dd format was changed to dd-mm-yy
        int day = digits[4]*10 + digits[5];
        if(day >= 1 and day <= 31)
            return true;

        return false;
    }

    bool checkControlSum(std::vector<int>& digits)
    {
        const std::vector<int> multipliers {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};

        //sum = (dig[i]*mul[i] + dig[i+1]*mul[i+1] + ...
        unsigned long int sum = std::inner_product(digits.begin(), digits.end(),
               multipliers.begin(), 0);

        if(sum % 10 == 0) 
            return true;

        return false;
    }
}

