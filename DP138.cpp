#include <bits/stdc++.h>
using namespace std;

void maxSumSubsequence(int arr[], int n, int k)
{
    int dp[n];

    dp[n - 1] = arr[n - 1];
    //9 8 7 6 5 4 3 2 1
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + k + 1 >= n)
        {
            dp[i] = max(arr[i], dp[i + 1]);
        }
        else
        {
            dp[i] = max(arr[i] + dp[i + k + 1], dp[i + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    cout << "\n";
    cout << "maximum sum of the subarray is:" << dp[0];
}

int main()
{
    int n = 10;
    int k = 2;
    int arr[] = {50, 70, 40, 50, 90, 70, 60, 40, 70, 50};
    maxSumSubsequence(arr, n, k);
    return 0;
}