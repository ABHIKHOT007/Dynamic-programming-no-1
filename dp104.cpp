#include <bits/stdc++.h>
using namespace std;

//longest alternating sequence.
//o(n)

void MaxelternatingSequence(int arr[], int n)
{
    int dp[n];
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] * arr[i + 1] < 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
}

int main()
{
    int arr[] = {1, -5, 1, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxelternatingSequence(arr, n);
    return 0;
}