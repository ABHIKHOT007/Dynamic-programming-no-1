#include <bits/stdc++.h>
using namespace std;

//maximum average path cost int matrix.

const int M = 100;

double maxAverageofPath(int arr[M][M], int N)
{
    int dp[N + 1][N + 1];

    dp[0][0] = arr[0][0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    for (int j = 1; j < N; j++)
    {
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] + arr[i][j]);
        }
    }
    return (double)dp[N - 1][N - 1] / (2 * N - 1);
}

int main()
{
    int arr[M][M] = {{1, 2, 3}, {6, 5, 4}, {7, 3, 9}};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout << "cost of the maximum average path is:" << maxAverageofPath(arr, 3);
    return 0;   
}