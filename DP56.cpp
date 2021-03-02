#include <bits/stdc++.h>
using namespace std;

//Longest Increasing Consecutive subsequence.
//o(n)

int LongestIncreasingConsecutiveSequence(int arr[], int n)
{
    unordered_map<int, int> hash;

    int dp[n];
    memset(dp, 0, sizeof(dp));
    int max_len = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (hash.find(arr[i] - 1) != hash.end())
        {
            int index = hash[arr[i] - 1] - 1;
            dp[i] = dp[index] + 1;
        }
        else
        {
            dp[i] = 1;
        }
        hash[arr[i]] = i + 1;
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

int main()
{
    int arr[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LongestIncreasingConsecutiveSequence(arr, n);
    return 0;
}