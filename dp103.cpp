#include <bits/stdc++.h>
using namespace std;

//Longest increasing subsequence.
//recursive sloution.
/*
int LISUtil(int arr[], int n, int *max_ref)
{
    if (n == 1)
    {
        return 1;
    }
    int res;
    int max_ending_here = 1;
    for (int i = 1; i < n; i++)
    {
        res = LISUtil(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
        {
            max_ending_here = res + 1;
        }
    }
    if (*max_ref < max_ending_here)
    {
        *max_ref = max_ending_here;
    }
    return max_ending_here;
}

int LIS(int arr[], int n)
{
    int max = 1;
    LISUtil(arr, n, &max);
    return max;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "longest length of the increasing sequence is:" << LIS(arr, n);
    return 0;
}*/

//o(n^2)
//tabluation solution apporach.

int LIS(int arr[], int n)
{
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the increasing sequence is:" << LIS(arr, n);
    return 0;
}