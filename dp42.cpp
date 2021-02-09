#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSum(int arr[], int n, int index, int k)
{
    if (index >= k)
    {
        return -1;
    }

    int dp[index + 1] = {0};
    int i;

    for (int i = 0; i <= index; i++)
    {
        dp[i] = arr[i];
    }

    int max_sum = INT_MIN;

    for (int i = 0; i <= index; i++)
    {
        if (arr[i] >= arr[k])
        {
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = dp[j] + arr[i];
            }
            max_sum = max(max_sum, dp[i]);
        }
    }
    if (max_sum == INT_MIN)
    {
        return arr[k];
    }
    return max_sum + arr[k];
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 4;
    int k = 6;
    cout << maxSum(arr, n, index, k);
    return 0;
}