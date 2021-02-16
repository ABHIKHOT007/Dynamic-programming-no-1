#include <bits/stdc++.h>
using namespace std;

//No of ways to cover distance
//o(3^n)
/*
int countWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}
*/

int countWays(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    int n = 4;
    cout<<"No of ways to cover the given disatnce is:"<<countWays(n);
    return 0;
}