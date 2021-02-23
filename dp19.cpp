#include <bits/stdc++.h>
using namespace std;

//Egg dropping problem.
//o(n^2)

int EggDropping(int n, int k)
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int res = INT_MAX;
                for (int mj = j - 1, pi = 0; mj >= 0; mj--, pi++)
                {
                    int v1 = dp[i][mj];
                    int v2 = dp[i - 1][pi];
                    int val = max(v1, v2);
                    res = min(val, res);
                }
                dp[i][j] = 1 + res;
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n = 2;
    int k = 10;
    cout << EggDropping(n, k);
    return 0;
}