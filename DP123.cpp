#include <bits/stdc++.h>
using namespace std;

//O(sum*n)

int subSetSumOfLongestLength(int arr[], int n, int sum)
{
    bool dp[sum + 1][n + 1];
    int count[sum + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = true;
        count[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = false;
        count[i][0] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            count[i][j] = count[i][j - 1];
            if (i >= arr[j - 1])
            {
                count[i][j] = max(count[i][j - 1], count[i - arr[j - 1]][j - 1]);
            }
        }
    }
    return count[sum][n];
}

int main()
{
    int arr[] = {2, 3, 5, 10};
    int sum = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subSetSumOfLongestLength(arr, n, sum);
    return 0;
}