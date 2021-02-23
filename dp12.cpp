#include <bits/stdc++.h>
using namespace std;

//Dice thrown problems.
//o(n*x)

int findWays(int f, int n, int s)
{
    long dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= s; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            if (j - f - 1 >= 0)
            {
                dp[i][j] -= dp[i - 1][j -f - 1];
            }
        }
    }
    return dp[n][s];
}

int main()
{
    cout << findWays(4, 2, 1);
    return 0;
}