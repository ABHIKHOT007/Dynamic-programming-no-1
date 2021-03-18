#include <bits/stdc++.h>
using namespace std;

//target sum subset.
//recursive solution.
//expoential time complexity.
/*
bool isSubsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }

    if(arr[n-1]>sum)
    {
        return isSubsetSum(arr,n-1,sum);
    }

    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;
    isSubsetSum(arr, n, sum) ? cout << "true" : cout << "false";
    return 0;
}
*/

//O(N^2)

bool isSubsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;
    isSubsetSum(arr, n, sum) ? cout << "YES" : cout << "NO";
    return 0;
}
