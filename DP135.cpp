#include <bits/stdc++.h>
using namespace std;

//O(N*M)

long long int maxProduct(int arr1[], int arr2[], int m, int n)
{
    long long int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + (arr1[j - 1] * arr2[i - 1]), dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    int arr1[] = {2, 3, 1, 7, 8};
    int arr2[] = {3, 6, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << maxProduct(arr1, arr2, m, n);
    return 0;
}