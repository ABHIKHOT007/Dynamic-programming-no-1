#include <bits/stdc++.h>
using namespace std;

//maximum possible stolen value from house.
//o(n)
//o(n)space
/*
int maxStolenvalue(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    if (n == 2)
    {
        return max(arr[0], arr[1]);
    }
    int dp[n + 1];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
}*/

int maxStolenvalue(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int val1 = arr[0];
    if (n == 1)
    {
        return val1;
    }
    int val2 = max(arr[0], arr[1]);
    if (n == 2)
    {
        return val2;
    }
    int max_val;
    for (int i = 2; i < n; i++)
    {
        max_val = max(arr[i] + val1, val2);
        val1 = val2;
        val2 = max_val;
    }
    return max_val;
}

int main()
{
    int arr[] = {6, 7, 1, 3, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxStolenvalue(arr, n) << "\n";
    return 0;
}