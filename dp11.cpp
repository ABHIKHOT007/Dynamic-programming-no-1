#include <bits/stdc++.h>
using namespace std;
//Egg dropping problem.
//Recursive apporach.

int max(int a, int b)
{
    return (a > b) ? a : b;
}
/*
int EggDrop(int n, int k)
{
    if (k == 1 || k == 0)
    {
        return k;
    }
    if (n == 1)
    {
        return k;
    }

    int min = INT_MAX;
    int x, res;

    for (x = 1; x <= k; x++)
    {
        res = max(EggDrop(n - 1, x - 1), EggDrop(n, k - x));
        if (res < min)
        {
            min = res;
        }
    }
    return min + 1;
}
*/
//tabulation method.
//o(n*k^2)

int EggDrop(int n, int k)
{
    int dp[n + 1][k + 1];
    int res;
    int i, j, x;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j <= k; j++)
    {
        dp[1][j] = j;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n = 2;
    int k = 10;
    cout << "Minimum number of trials in worst case with" << n << "eggs and" << k << "florr are:" << EggDrop(n, k);
    return 0;
}