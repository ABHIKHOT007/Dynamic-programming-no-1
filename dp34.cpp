#include <bits/stdc++.h>
using namespace std;

//Coin change permuatation.
//o(n^2) time complexity
//o(n) space complexity

int CoinChangePermuation(int arr[], int n, int tar)
{
    int dp[tar + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[tar];
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tar = 4;
    cout << CoinChangePermuation(arr, n, tar);
    return 0;
}