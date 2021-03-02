#include <bits/stdc++.h>
using namespace std;

//Longest alternating subsequence
//o(n^2)

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LongestAlternatingSubsequence(int arr[], int n)
{
    int dp[2][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = 1;
    }

    //dp[i][0]=the element greater than the last element.
    //dp[i][1]=the element smaller thant the last element.

    int res = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i][0] < dp[j][1] + 1)
            {
                dp[i][0] = dp[j][1] + 1;
            }
            if (arr[j] > arr[i] && dp[i][1] < dp[j][0] + 1)
            {
                dp[i][1] = dp[j][0] + 1;
            }
        }
        if (res < max(dp[i][0], dp[i][1]))
        {
            res = max(dp[i][0], dp[i][1]);
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Lenght of the longest subsequence is:" << LongestAlternatingSubsequence(arr, n);
    return 0;
}