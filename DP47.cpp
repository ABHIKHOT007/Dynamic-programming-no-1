#include <bits/stdc++.h>
using namespace std;

//how recursive call are mades.
//recursion solutions.

int Recursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    cout << "pre\n"
         << n << "\n";
    Recursion(n - 1);
    cout << "in\n"
         << n << "\n";
    Recursion(n - 1);
    cout << "past\n"
         << n << "\n";
}

int main()
{
    int n = 5;
    cout << Recursion(n);
    return 0;
}