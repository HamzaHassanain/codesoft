#include "Clear.h"

void Clear()
{
#ifdef _WIN32
    system("cls");
#elif _WIN64
    system("cls");
#else
    system("clear");
#endif
}