#include <bits/stdc++.h>
using namespace std;

//minimum numbers of steps to reduce the number to 1
/*
int countSteps(int n)
{
    int steps = 0;
    while (n > 1)
    {
        if (n % 3 == 0)
        {
            n /= 3;
        }
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n--;
        }
        steps++;
    }
    return steps;
}
*/
/*memoization method
int countSteps(int n, int *dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int steps = countSteps(n - 1, dp);

    if (n % 2 == 0)
    {
        steps = min(steps, countSteps(n / 2, dp));
    }
    if (n % 3 == 0)
    {
        steps = min(steps, countSteps(n / 3, dp));
    }

    dp[n] = 1 + steps;
    return dp[n];
}

int getminSteps(int n)
{
    int dp[n + 1];
   memset(dp,-1,sizeof(dp));
    return countSteps(n, dp);
}

int main()
{
    int n = 10;
    cout << getminSteps(n);
    return 0;
}
*/

//tabulation method

int countSteps(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = n - i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (!(i % 2))
        {
            dp[i / 2] = min(dp[i] + 1, dp[i / 2]);
        }
        if (!(i % 3))
        {
            dp[i / 3] = min(dp[i] + 1, dp[i / 3]);
        }
    }
    return dp[1];
}

int main()
{
    int n = 10;
    cout << countSteps(n);
    return 0;
}