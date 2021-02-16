#include <bits/stdc++.h>
using namespace std;

//minimum steps to convert the sequence into strictly increasing subsequence.
//o(N^2)

int MinChanges(int arr[], int n)
{
    int dp[n];
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && (i - j) <= (arr[i] - arr[j]))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    return n - len;
}

int main()
{
    int arr[] = {1, 2, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MinChanges(arr, n);
    return 0;
}
