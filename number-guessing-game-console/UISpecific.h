#pragma once

#include <iostream>

class UISpecific
{

public:
    static void ShowError(std::string message);
    static void PrintOutput(std::string output);
    static void ClearScreen();
    static std::string ReadInput();
    static bool IsUIPossitve(char input);
    static std::string GetUI_YES_NO();
    static std::string GetUI_WELCOME();
    static std::string GetUI_GUESS_MESSAGE();
    static std::string GetUI_GUESS_AGAIN_LOWER();
    static std::string GetUI_GUESS_AGAIN_HIGHER();
    static std::string GetUI_CORRECT_GUESS();
    static std::string GetUI_GUESS_COUNT(int count);
    static std::string GetUI_PLAY_AGAIN();
};
