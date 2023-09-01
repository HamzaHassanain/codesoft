#include "Interactor.h"
#include "Parser.h"
#include "UISpecific.h"
#include <iostream>

Interactor::Interactor()
{
}

std::string Interactor::Read(std::string output)
{
    Write(output);

    return UISpecific::ReadInput();
}

void Interactor::Write(std::string output)
{
    UISpecific::PrintOutput(output);
}
Interactor::~Interactor()
{
}