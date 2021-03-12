#include <bits/stdc++.h>
using namespace std;

int CountAdjecentOnces(int n, int k)
{
    int dp[n][k][2];
    memset(dp, 0, sizeof(dp));

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        { 
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j - 1][0];
            if (j - 1 >= 0)
            {
                dp[i][j][1] += dp[i - 1][j - 1][1];
            }
        }
    }
    return dp[n][k][0] + dp[n][k][1];
}
int main()
{
    int n = 5, k = 2;
    cout << CountAdjecentOnces(n, k);
    return 0;
}