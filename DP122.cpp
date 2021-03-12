#include <bits/stdc++.h>
using namespace std;

//O(N^2)
//Maximum profit from the wines.

#define N 1000

int dp[N][N];
int sell[N][N];

int maxProfitUtil(int arr[], int begin, int end, int n)
{
    if (dp[begin][end] != -1)
    {
        return dp[begin][end];
    }

    int year = n - (end - begin);

    if (begin == end)
    {
        return year * arr[begin];
    }

    int x = arr[begin] * year + maxProfitUtil(arr, begin + 1, end, n);
    int y = arr[end] * year + maxProfitUtil(arr, begin, end - 1, n);

    int ans = max(x, y);
    dp[begin][end] = ans;

    if (x >= y)
    {
        sell[begin][end] = 0;
    }
    else
    {
        sell[begin][end] = 1;
    }

    return ans;
}

void maxProfit(int arr[], int n)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = maxProfitUtil(arr, 0, n - 1, n);

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (sell[start][end] == 0)
        {
            cout << "beg"
                 << " ";
            start++;
        }
        else
        {
            cout << "end"
                 << " ";
            end--;
        }
    }
    cout << "\n";
    cout << ans << "\n";
}

int main()
{
    int arr[] = {2, 4, 6, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxProfit(arr, n);
    return 0;
}