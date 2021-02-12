#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

//minimum removels from array
//o(n^2)
/*
int countRemovels(int arr[], int i, int j, int k)
{
    if (i >= j)
    {
        return 0;
    }
    else if ((arr[j] - arr[i]) < k)
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else if ((arr[j] - arr[i]) > k)
    {
        dp[i][j] = 1 + min(countRemovels(arr, i + 1, j, k), countRemovels(arr, i, j - 1, k));
    }
    return dp[i][j];
}

int removals(int arr[], int n, int k)
{
    sort(arr, arr + n);

    memset(dp, -1, sizeof(dp));
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return countRemovels(arr, 0, n - 1, k);
    }
}

int main()
{
    int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << removals(arr, n, k);
    return 0;
}
*/

