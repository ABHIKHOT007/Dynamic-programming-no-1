#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int pathCountUtil(int arr[][C], int m, int n, int k)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0 && n == 0)
    {
        return k = arr[m][n];
    }

    return pathCountUtil(arr, m - 1, n, k - arr[m][n]) + pathCountUtil(arr, m, n - 1, k - arr[m][n]);
}

int pathCount(int arr[][C], int k)
{
    return pathCountUtil(arr, R - 1, C - 1, k);
}

int main()
{
    int k = 12;
    int arr[][C] = {{1, 2, 3}, {4, 6, 5}, {3, 2, 1}};
    cout << pathCount(arr, k);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
#define MAX_X 10000

int dp[R][C][MAX_X];

int pathCountUtil(int arr[][C], int m, int n, int k)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }

    if (m == 0 && n == 0)
    {
        return k = arr[m][n];
    }

    if (dp[m][n][k] != -1)
    {
        return dp[m][n][k];
    }

    dp[m][n][k] = pathCountUtil(arr, m - 1, n, k - arr[m][n]) + pathCountUtil(arr, m, n - 1, k - arr[m][n]);

    return dp[m][n][k];
}

int pathCount(int arr[][C], int k)
{
    memset(dp, -1, sizeof(dp));
    return pathCountUtil(arr, R - 1, C - 1, k);
}

int main()
{
    int k = 12;
    int arr[R][C] = {{1, 2, 3}, {4, 5, 6}, {3, 2, 1}};
    cout << pathCount(arr, k);
    return 0;
}