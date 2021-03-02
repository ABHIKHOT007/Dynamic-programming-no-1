#include <bits/stdc++.h>
using namespace std;

//Longest alternating subsequence.
//Alternating sequence is one following property.
//x1<x2>x3<x4>x5<....xn.
//or
//x1>x2<x3>x4<x5>....xn.
//o(n^2)

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LongestAlternatingSubsequence(int arr[], int n)
{
    int dp[n][2];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = 1;
    }

    int res = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            //if arr[i] is greater then check
            //dp[j][1]

            if (arr[j] < arr[i] && dp[i][0] < dp[j][1] + 1)
            {
                dp[i][0] = dp[j][1] + 1;
            }

            //if arr[i] is smaller then check.
            //dp[j][0]
            
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
    cout << "Longest alternating subsequence is:" << LongestAlternatingSubsequence(arr, n) << "\n";
    return 0;
}
