#include <bits/stdc++.h>
using namespace std;

int parse(string expression)
{
}

int main()
{
    string expression = "1 + 5 * (3 - 4) / 2";
    // erase all spaces
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    // parse math expression
    int ans = parse(expression);
}