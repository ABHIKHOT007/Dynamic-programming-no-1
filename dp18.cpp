#include <bits/stdc++.h>
using namespace std;
#define N 100

//Stacking the tiles on each other by length wise.
//o(n^2)

int StackingTiles(int n, int m, int k)
{
    int dp[N][N];
    int preSum[N][N];
    memset(dp, 0, sizeof(dp));
    memset(preSum, 0, sizeof(preSum));

    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = 0;
        preSum[0][i] = 1;
    }

    for (int i = 0; i < m + 1; i++)
    {
        preSum[i][0] = dp[i][0] = 1;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            dp[i][j] = preSum[i - 1][j];
            if (j > k)
            {
                dp[i][j] -= preSum[i - 1][j - k - 1];
            }
        }
        for (int j = 1; j < n + 1; j++)
        {
            preSum[i][j] = dp[i][j] + preSum[i][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{
    int n = 3, m = 3, k = 2;
    cout << StackingTiles(n, m, k);
    return 0;
}