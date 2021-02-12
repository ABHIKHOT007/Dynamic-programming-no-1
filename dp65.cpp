#include <bits/stdc++.h>
using namespace std;
#define N 4
//Maximum sum of the path in the matrix.
//o(n^2)

int maxSumPath(int arr[][4], int n)
{
    int result = 0;

    int dp[N][N + 2];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        dp[0][i + 1] = arr[0][i];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + arr[i][j - 1];
        }
    }
    for (int i = 0; i <= N; i++)
    {
        result = max(result, dp[N - 1][i]);
    }
    return result;
}

int main()
{
    int arr[4][4] = {{4, 2, 3, 4},
                     {2, 9, 1, 10},
                     {15, 1, 3, 0},
                     {16, 92, 41, 44}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumPath(arr, n);
    return 0;
}