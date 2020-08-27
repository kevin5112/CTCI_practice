#include <iostream>
#include <string>


std::string urlify(std::string str);
std::string IncreaseSpace(std::string str);


int     main()
{
    std::string str1 = "Mr John Smith    ";
    std::string str2;

    // std::cout << "Input string1: ";
    // std::cin >> str1;

    // str1 = IncreaseSpace(str1);

    str2 = urlify(str1);

    std::cout << "Input: " << str1 << ", " << str1.size() - 4 << std::endl;
    std::cout << "Output: " << str2 << std::endl;

    return 0;
}

std::string urlify(std::string str)
{
    std::string     newStr = str;
    int             counter = 0;

    if(str.empty() || (str.size() == 1 && str[1] != ' '))
        return str;

    for(int i = 0; i < str.size(); ++i)
    {
        //std::cout << newStr << std::endl;
        if(str[i] == ' ')
        {
            newStr[counter++] = '%';
            newStr[counter++] = '2';
            newStr[counter++] = '0';
            ++i;
        }
        newStr[counter++] = str[i];
    }
    //std::cout << "returning: " << newStr << std::endl;
    return newStr;
}

/* std::string IncreaseSpace(std::string str)
{
    std::string newStr;
    int counter = 0;

    for(auto it = str.begin(); it != str.end(); ++it)
    {
        if(*it == ' ')
        {
            ++counter;
        }
    }

    for(int i = 0; i < counter; ++i)
    {
        auto it = str.end();

        *it = ' ';

    }

    auto it = str.end() + 1;
    *it = 0;
    return str;
} */