#include <bits/stdc++.h>
using namespace std;

//minimum cost path in 3D matrix.
//O(N*M*K)
//where n,m & k are the three dimensions.

#define l 3
#define m 3
#define n 3

int min(int x, int y, int z)
{
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int minPathCost(int arr[][m][n])
{
    int dp[l][m][n];
    dp[0][0][0] = arr[0][0][0];

    for (int i = 1; i < l; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + arr[i][0][0];
    }

    for (int j = 1; j < m; j++)
    {
        dp[0][j][0] = dp[0][j - 1][0] + arr[0][j][0];
    }

    for (int k = 1; k < n; k++)
    {
        dp[0][0][k] = dp[0][0][k - 1] + arr[0][0][k - 1];
    }

    for (int i = 1; i < l; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0], INT_MAX) + arr[i][j][0];
        }
    }

    for (int i = 1; i < l; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][0][j] = min(dp[i - 1][0][j], dp[i][0][j - 1], INT_MAX) + arr[i][0][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[0][i][j] = min(dp[0][i][j - 1], dp[0][i - 1][j], INT_MAX) + arr[0][i][j];
        }
    }

    for (int i = 1; i < l; i++)
    {
        for (int j = 1; j < m; j++)
        {
            for (int k = 1; k < n; k++)
            {
                dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]) + arr[i][j][k];
            }
        }
    }

    return dp[l - 1][m - 1][n - 1];
}

int main()
{
    int arr[l][m][n] = {{{1, 2, 4}, {3, 4, 5}, {5, 2, 1}},
                        {{4, 8, 3}, {5, 2, 1}, {3, 4, 2}},
                        {{2, 4, 1}, {3, 1, 4}, {6, 3, 8}}};

    cout << minPathCost(arr);
    return 0;
}