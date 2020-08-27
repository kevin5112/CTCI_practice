#include <iostream>
#include <string>

bool PalindromePermutation(std::string str);

int     main()
{
    std::string string1 = "taco cat";
    if(PalindromePermutation(string1))
        std::cout << "True\n";
    else
        std::cout << "False\n";
    
    return 0;
}

bool PalindromePermutation(std::string str)
{
    if(str.empty())
        return false;
    
    int whiteSpace = 0;
    int array[128] = {0};
    
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ' ')
            ++whiteSpace;
    }

    int strSize = str.size() - whiteSpace;
    bool isEven = false;

    if(strSize % 2 == 0)
        isEven = true;
    
    //std::cout << "isEven: " << isEven << " strSize: " << strSize << std::endl;

    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] != ' ')
            ++array[str[i]];
    }

    if(isEven)
    {
        //std::cout << "isEven is true\n";
        for(int i = 0; i < 128; ++i)
        {
            if(!(array[i] == 0 || array[i] == 2))
                return false;
        }
    }
    else
    {
        //std::cout << "isEven is false\n";
        int oneOdd = 0;
        for(int i = 0; i < 128; ++i)
        {
            // std::cout << "oneOdd: " << oneOdd << '[' << i << ']' << std::endl;
            if(array[i] == 1 && oneOdd == 0)
            {
                //std::cout << "yes0\n";
                ++oneOdd;
            }
            else if(array[i] == 1 && oneOdd != 0)
            {   
                //std::cout << "i: " << i << "array[i]: " << array[i] << std::endl;
                //std::cout << "yes1\n";
                return false;
            }
            else if(!(array[i] == 0 || array[i] == 2))
            {
                //std::cout << "yes2\n";
                return false;
            }
        }
    }
    return true;
}