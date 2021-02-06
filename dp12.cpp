#include <bits/stdc++.h>
using namespace std;

//no of ways of paring the friends
//o(n)
/*
int CountnoOfWays(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
    }
    return dp[n];
}*/

//using recursion formula

int dp[1000];

int CountnoOfWays(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n > 2)
    {
        return dp[n] = CountnoOfWays(n - 1) + (n - 1) * CountnoOfWays(n - 2);
    }
    else
    {
        return dp[n] = n;
    }
}
int main()
{
    int n = 4;
    memset(dp, -1, sizeof(dp));

    cout << "no of ways of paring the friends are:" << CountnoOfWays(n) << "\n";
    return 0;
}