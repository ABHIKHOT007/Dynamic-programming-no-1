#include <bits/stdc++.h>
using namespace std;
long long dp[100][1000];

//minimum sum of multiplication of n numbers

long long minSum(int arr[], int i, int j)
{
    long long ans = 0;
    for (int m = i; m <= j; m++)
    {
        ans = (ans + arr[m]) % 100;
    }
    return ans;
}

long long solve(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], (solve(arr, i, k) + solve(arr, k + 1, j) + minSum(arr, i, k) * minSum(arr, k + 1, j)));
    }
    return dp[i][j];
}

int main()
{
    int arr[] = {40, 60, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 0, n - 1);
    return 0;
}