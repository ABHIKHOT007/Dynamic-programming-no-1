#include <bits/stdc++.h>
using namespace std;

//Coin Change combination.
//o(n^2)time complixity.
//o(n)space complexity.

int CoinChangeCombition(int arr[], int n, int tar)
{
    int dp[tar + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= tar; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[tar];
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tar = 4;
    cout << CoinChangeCombition(arr, n, tar);
    return 0;
}