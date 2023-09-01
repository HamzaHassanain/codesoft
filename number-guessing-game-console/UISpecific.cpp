#include "UISpecific.h"
void UISpecific::ShowError(std::string message)
{
    std::cout << "Error: " << message << std::endl;
}
void UISpecific::PrintOutput(std::string output)
{
    std::cout << output;
}
void UISpecific::ClearScreen()
{
    system("clear");
}
std::string UISpecific::ReadInput()
{
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}
std::string UISpecific::GetUI_WELCOME()
{
    return "Welcome to the number guessing game!\n";
}
std::string UISpecific::GetUI_GUESS_MESSAGE()
{
    return "Guess a number between 1 and 1000: ";
}
std::string UISpecific::GetUI_GUESS_AGAIN_LOWER()
{
    return "Too low! Guess again: ";
}
std::string UISpecific::GetUI_GUESS_AGAIN_HIGHER()
{
    return "Too high! Guess again: ";
}
std::string UISpecific::GetUI_CORRECT_GUESS()
{
    return "You guessed the number!\n";
}
std::string UISpecific::GetUI_GUESS_COUNT(int count)
{
    return "You did it in " + std::to_string(count) + " guesses!\n";
}
std::string UISpecific::GetUI_PLAY_AGAIN()
{
    return "Play again? Y/N: ";
}
bool UISpecific::IsUIPossitve(char input)
{
    return input == 'y' || input == 'Y';
}
