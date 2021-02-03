#include <bits/stdc++.h>
using namespace std;

/*
o(n^2)

int min(int x, int y);

int permutaionfactor(int n, int k)
{
    int p[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0)
            {
                p[i][j] = 1;
            }
            else
            {
                p[i][j] = p[i - 1][j] + (j * p[i - 1][j-1]);
            }
            p[i][j + 1] = 0;
        }
    }
    return p[n][k];
}

int min(int x, int y)
{
    return (x > y) ? x : y;
}*/

/*
o(n)

int permutaionfactor(int n, int k)
{
    int fact[n + 1];
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    return fact[n] / fact[n - k];
}
*/

//o(n)
//o(n)space complexity.

int permutaionfactor(int n, int k)
{
    int p = 1;

    for (int i = 0; i < k; i++)
    {
        p *= (n - i);
    }

    return p;
}

int main()
{
    int n = 10, k = 2;
    cout << "value of coefficent is:" << permutaionfactor(n, k) << "\n";
    return 0;
}