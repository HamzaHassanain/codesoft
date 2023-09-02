#pragma once
#include <string>
class Interactor
{
public:
    Interactor();

    std::string Read(std::string output = "");

    void Write(std::string output);

    ~Interactor();
};