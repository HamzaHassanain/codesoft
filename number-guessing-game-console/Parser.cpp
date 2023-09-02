#include "Parser.h"
#include <iostream>
int Parser::ParseInt(std::string input)
{
    std::string message = input + ": " + " Is not a valid int";
    // is int
    if (int(input.size()) > 0)
    {
        for (int i = 0; i < int(input.size()); i++)
        {
            if (!isdigit(input[i]))
            {
                std::cerr << message << std::endl;
                return -1;
            }
        }
        return std::stoi(input);
    }
    std::cerr << message << std::endl;
    return -1;
}

char Parser::ParseChar(std::string input)
{
    std::string message = input + ": " + " Is not a valid char";

    if (int(input.size()) == 1)
    {
        if (isalpha(input[0]))
            return input[0];
    }
    std::cerr << message << std::endl;
}