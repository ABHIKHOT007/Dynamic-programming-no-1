#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

//maximum sumof the maxrix from the top to the bottom
//O(N^2)

int maxSum(int arr[SIZE][SIZE], int n)
{
    if (n == 1)
    {
        return arr[0][0];
    }

    int dp[n][n];
    int maxsum = INT_MIN, max;

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = arr[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            max + INT_MIN;
            if ((j - 1) >= 0 && (max < dp[i + 1][j - 1]))
            {
                max = dp[i + 1][j - 1];
            }
            if ((j + 1) < n && (max < dp[i + 1][j + 1]))
            {
                max = dp[i + 1][j + 1];
            }
            dp[i][j] = arr[i][j] + max;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (maxsum < dp[0][j])
        {
            maxsum = dp[0][j];
        }
    }

    return maxsum;
}

int main()
{
    int arr[SIZE][SIZE] = {{5, 6, 1, 7},
                           {-2, 10, 8, -1},
                           {3, -7, -9, 11},
                           {12, -4, 2, 6}};
    int n = 4;
    cout << maxSum(arr, n);
    return 0;
}