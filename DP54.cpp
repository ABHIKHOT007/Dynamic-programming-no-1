#include <bits/stdc++.h>
using namespace std;

//Longest increasing Odd Even subsequence.
//o(n^2)

int LIOES(int arr[], int n)
{
    int dp[n];
    memset(dp, 1, sizeof(dp));
    int maxLen = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && (arr[i] + arr[j]) % 2 != 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (maxLen < dp[i])
        {
            maxLen = dp[i];
        }
    }
    return maxLen;
}

int main()
{
    int arr[] = {5, 6, 9, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LIOES(arr, n);
    return 0;
}