#include <bits/stdc++.h>
using namespace std;

int CountWasy(int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n; i++)
    {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++)
    {
        dp[i] += dp[i - 10];
    }
    return dp[n];
}

int main()
{
    int n = 20;
    cout << "Number of ways to reach are:" << CountWasy(n);
    return 0;
}