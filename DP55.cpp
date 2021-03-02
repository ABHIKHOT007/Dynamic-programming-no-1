
#include <bits/stdc++.h>
using namespace std;


//No of increasing subsequence of the length k.
//o(nk)

int NoofIncreasingOfsizeK(int arr[], int n, int k)
{
    int dp[k][n];
    int sum = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }

    for (int l = 1; l < k; l++)
    {
        for (int i = l; i < n; i++)
        {
            dp[l][i] = 0;
            for (int j = l - 1; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    dp[l][i] += dp[l - 1][j];
                }
            }
        }
    }

    for (int i = k - 1; i < n; i++)
    {
        sum += dp[k - 1][i];
    }
    return sum;
}

int main()
{
    int arr[] = {12, 8, 11, 13, 10, 15, 14, 16, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << NoofIncreasingOfsizeK(arr, n, k);
    return 0;
}