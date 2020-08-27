#include <iostream>
#include <string>

bool    CheckPerm(std::string string1, std::string string2);

int     main()
{
    std::string string1 = "racecar";
    std::string string2 = "car";

    std::cout << "Enter string1: ";
    std::cin >> string1;
    std::cout << "Enter string2: ";
    std::cin >> string2;

    if(CheckPerm(string1, string2))
    {
        std::cout << "Your answer is... true!" << std::endl;
    }
    else 
    {
        std::cout << "Your answer is... false!" << std::endl;
    }
    

    return 0;
}

bool    CheckPerm(std::string str1, std::string str2)
{
    std::string bigStr;
    std::string smallStr;

    if((str1.empty()) || (str2.empty()))
    {   
        std::cout << "returning from first if statement\n";
        return false;
    }

    if(str1.size() > str2.size())
    {
        bigStr = str1;
        smallStr = str2;
    }
    else if(str2.size() > str1.size())
    {
        bigStr = str2;
        smallStr = str1;
    }
    else
    {
        for(std::string::iterator it1 = str1.begin(), it2 = str2.begin(); it1 != str1.end(); ++it1, ++it2)
        {
            if(*it1 != *it2)
            {
                std::cout << "returning from when strings are same length but different letters\n";
                return false;
            }
        }
        std::cout << "returning from when strings are same length and same word\n";
        return true;
    }

    int small = 0;

//party
//pa

    for(int i = 0; i < bigStr.size(); i++)
    {
        if(bigStr[i] == smallStr[small])
        {
            for(small; small < smallStr.size() && i + small < bigStr.size(); small++)
            {
                if (bigStr[i + small] != smallStr[small])
                {
                    std::cout << "i: " << i << " small: " << small << std::endl;
                    break;
                }
            }

            if (small >= smallStr.size())
            {
                return true;
            }
            else
            {
                small = 0;
            }
        }

    }

    return false;
/*
    for(std::string::iterator it1 = bigStr.begin(), it2 = smallStr.begin(); it2 != smallStr.end(); ++it1)
    {
        std::cout << "entering forloop: " << *it1 << std::endl;
        if(it1 == bigStr.end())
        {
            return false;
        }
        if(*it1 == *it2)
        {
            if(it2 == smallStr.end())
            {
                std::cout << "returning when string is perm... yes!\n";
                return true;
            }
            ++it2;
        }
    }
    */

    std::cout << "return from end of function...\n";
    return true; // couldn't find first letter in string
}