#include <bits/stdc++.h>
using namespace std;

//Number of n-digits non decrsing integer forming.
//o(10*n)

int NoOfnonDecrsingIntegerWays(int n)
{
    int dp[n + 1][10];
    for (int i = 0; i <= 9; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][9] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 8; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
        }
    }
    return dp[n][0];
}

int main()
{
    int n = 2;
    cout << "Non-decreasing digits are::" << NoOfnonDecrsingIntegerWays(n);
    return 0;
}