#include <bits/stdc++.h>
using namespace std;

const int MAX=1000;

int maxcost(int arr[][MAX], int n)
{
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = arr[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i + 1 && j < n; j++)
        {
            dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (result < dp[n - 1][i])
        {
            result = dp[n - 1][i];
        }
    }
    return result;
}

int main()
{
    int arr[MAX][MAX] = {{4, 1, 5, 6, 1},
                         {2, 9, 2, 11, 10},
                         {15, 1, 3, 15, 2},
                         {16, 92, 41, 4, 3},
                         {8, 142, 6, 4, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum path cost is:" << maxcost(arr, n) << "\n";
    return 0;
}