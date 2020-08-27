#include <iostream>
#include <string>

bool CheckPermutation(std::string string1, std::string string2);

int     main()
{
    std::string string1 = "fail";
    std::string string2 = "alfi";

    std::cout << "Enter string1: ";
    std::cin >> string1;
    std::cout << "Enter string2: ";
    std::cin >> string2;

    if(CheckPermutation(string1, string2))
    {
        std::cout << "Yes!\n";
    }
    else
    {
        std::cout << "No!\n";
    }

    return 0;
}


bool    CheckPermutation(std::string string1, std::string string2)
{
    int array[128] = {0};

    if((string1.empty()) || (string2.empty()))
    {
        return false;
    }

    if(string1.size() != string2.size())
    {
        return false;
    }

    for(int i = 0; i < string1.length(); ++i)
    {
        ++array[string1[i]];
        --array[string2[i]];
        
        // std::cout << array[string1[i]] << ' ' << std::endl;
    }

    for(int i = 0; i < 128; ++i)
    {
        if(array[i] != 0)
        {
            return false;
        }
    }
    return true;
}