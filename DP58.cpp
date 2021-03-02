#include <bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequence(int arr[], int n)
{
    set<int> hashset;

    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr[i]);
    }

    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        if (!hashset.count(arr[i] - 1))
        {
            int num = arr[i];
            int curr = 1;
            while (hashset.count(num + 1))
            {
                num += 1;
                curr += 1;
            }
            max_len = max(max_len, curr);
        }
    }
    return max_len;
}

int main()
{

    int arr[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "longest increasing subsequence is:" << LongestIncreasingSubsequence(arr, n);
    return 0;
}