#include <bits/stdc++.h>
using namespace std;
#define NTL -1
#define MAX 100

//Memoization based apporach for fibnacci sequence.
/*
int lookup[MAX];

void _initailize()
{
    for (int i = 0; i < MAX; i++)
    {
        lookup[i] = NTL;
    }
}

int fib(int n)
{
    if (lookup[n] == NTL)
    {
        if (n <= 1)
        {
            lookup[n] = n;
        }
        else
        {
            lookup[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return lookup[n];
}

int main()
{
    _initailize();
    int n = 5;
    cout << "fibnoacci of given number is:" << fib(n);
    return 0;
}*/

//Tabulation based apporach.

int fib(int n)
{
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main()
{
    int n = 9;
    cout << "Fibnoacci of given nuber is\n" << fib(n) << endl;
    return 0;
}