#include <bits/stdc++.h>
using namespace std;

//Moser-de Bruijn sequence.
/*
int gen(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    else if (n % 2 == 0)
    {
        return 4 * gen(n / 2);
    }
    else if (n % 2 == 1)
    {
        return 4 * gen(n / 2) + 1;
    }
   
}
*/

int gen(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = 4 * dp[i / 2];
        }
        else
        {
            dp[i] = 4 * dp[i / 2] + 1;
        }
    }
}

int moserde(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << gen(i) << " ";
    }
    cout << "\n";
}

int main()
{
    int n = 15;
    moserde(n);
    return 0;
}