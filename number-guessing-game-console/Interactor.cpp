#include "Interactor.h"
#include "Parser.h"
#include <iostream>

Interactor::Interactor()
{
}

std::string Interactor::Read(std::string output)
{
    Write(output);

    std::string input;
    std::getline(std::cin >> std::ws, input);

    return input;
}

void Interactor::Write(std::string output)
{
    std::cout << output;
}
Interactor::~Interactor()
{
}