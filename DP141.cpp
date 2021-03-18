#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 4
//maximum decimal value path in binary matrix.
//recursive solution
/*
int maxDecimalValueinBinarymatrix(int arr[][M], int i, int j, int p)
{
    if (i >= N || j >= M)
    {
        return 0;
    }

    int result = max(maxDecimalValueinBinarymatrix(arr, i, j + 1, p + 1), maxDecimalValueinBinarymatrix(arr, i + 1, j, p + 1));
    if (arr[i][j] == 1)
    {
        return pow(2, p) + result;
    }
    else
    {
        return result;
    }
}

int main()
{
    int arr[N][M] = {{1, 1, 0, 1},
                     {0, 1, 1, 0},
                     {1, 0, 0, 1},
                     {1, 0, 1, 1}};
    cout << maxDecimalValueinBinarymatrix(arr, 0, 0, 0);
    return 0;
}
*/
//O(n^2)

long long int maxSum(int arr[][N], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    if (arr[0][0] == 1)
    {
        dp[0][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[0][i] == 1)
        {
            dp[0][i] = dp[0][i - 1] + pow(2, i);
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] == 1)
        {
            dp[i][0] = dp[i - 1][0] + pow(2, i);
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + pow(2, i + j));
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main()
{
    int arr[][4] = {{1, 1, 0, 1},
                    {0, 1, 1, 0},
                    {1, 0, 0, 1},
                    {1, 0, 1, 1}};
    cout << maxSum(arr, 4);
    return 0;
}