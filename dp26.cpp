#include <bits/stdc++.h>
using namespace std;

//reverse fibnoacci sequence

int reversefib(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << dp[i] << " ";
    }
}

int main()
{
    int n=10;
    reversefib(n);
    return 0;
}