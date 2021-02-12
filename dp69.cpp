#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];

//matrix chain mulitiplication

//recursive solution
/*
int maxtirxChainorder(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int k;
    int count;
    int min = INT_MAX;

    for (int k = i; k < j; k++)
    {
        count = maxtirxChainorder(arr, i, k) + maxtirxChainorder(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (count < min)
        {
            min = count;
        }
    }
    return min;
}
*/
//memoization solution

int maxtirxChainorder(int arr[], int i, int j)
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
        dp[i][j] = min(dp[i][j], (maxtirxChainorder(arr, i, j) + maxtirxChainorder(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]));
    }
    return dp[i][j];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    cout << "minimum number of multiplications is:" << maxtirxChainorder(arr, 1, n - 1);
    return 0;
}