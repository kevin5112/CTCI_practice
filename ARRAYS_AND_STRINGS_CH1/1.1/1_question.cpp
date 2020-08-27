/*
    Question 1.
    1.1 Is Unique: Implement an algorith to determine if a string has 
    all unique characters. What if you cannot use additional data 
    structures?
    Date: 10/1/18
*/


#include <iostream>
#include <string>

bool IsUnique(std::string str);
bool IsUnique2(std::string str);

int     main()
{
    std::string string1;
    bool bResult;
    
    std::cout << "Enter string: ";
    std::getline(std::cin, string1);
    bResult = IsUnique2(string1);
    if(bResult == 1)
        std::cout << "result is true" << std::endl;
    else
        std::cout << "result is false" << std::endl;

    return 0;
}




bool IsUnique(std::string str)
{
    bool bVal = true;
    bool array[26] = {0};

    if(str.empty())
    {
        return bVal;
    }

    if(str.size() == 1)
    {
        return bVal;
    }

    for(std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if((*it >= 'a') && (*it <= 'z'))
        {
            if(array[*it - 'a'] == 1)
            {
                bVal = false;
                break;
            }
            array[*it - 'a'] = true;
        }

        if((*it >= 'A') && (*it <= 'Z'))
        {
            if(array[*it - 'A'] == 1)
            {
                bVal = false;
                break;
            }
            array[*it - 'A'] = true;
        }
    }
    return bVal;    
}

bool IsUnique2(std::string str)
{
    bool bVal = true;
    bool array[127] = {0};

    // std::cout << str << std::endl;

    if(str.empty())
    {
        return bVal;
    }

    if(str.size() == 1)
    {
        return bVal;
    }

    for(std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        // std::cout << *it << std::endl;
        if((array[*it] == 1) && (*it != ' '))
        {
            bVal = false;
        }
        array[*it] = true;
    }
    return bVal;
}