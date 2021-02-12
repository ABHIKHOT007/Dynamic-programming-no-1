#include <bits/stdc++.h>
using namespace std;

//Maximum sum of pairs with specific difference.
//o(nlogn)
/*
int maxSumpair(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int dp[n];

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        if (arr[i] - arr[i - 1] < k)
        {
            if (i >= 2)
            {
                dp[i] = max(dp[i], dp[i - 2] + arr[i] + arr[i - 2]);
            }
            else
            {
                dp[i] = max(dp[i], arr[i] + arr[i - 1]);
            }
        }
    }
    return dp[n - 1];
}
*/

int maxSumpair(int arr[], int n, int k)
{
    int max_sum = 0;

    sort(arr, arr + n);

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] - arr[i - 1] < k)
        {
            max_sum += arr[i];
            max_sum += arr[i - 1];
            i--;
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << maxSumpair(arr, n, k);
    return 0;
}
