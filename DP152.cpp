#include <bits/stdc++.h>
using namespace std;

//maximum adjcent sum in the given array.
//O(N)

int maxAdjecentSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    int dp[n + 1];
    dp[0] = arr[0];
    dp[1] = arr[0] > arr[1] ? arr[0] : arr[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxAdjecentSum(arr, n);
    return 0;
}