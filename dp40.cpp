#include <bits/stdc++.h>
using namespace std;

//maximum subsequence with difference between adjacent element as either 0 or 1.
//o(n^2)

int maxLengthSequence(int arr[], int n)
{
    int dp[n], max = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) <= 1 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i])
        {
            max = dp[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {2, 5, 6, 3, 7, 6, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum length subsequence is:" << maxLengthSequence(arr, n);
    return 0;
}