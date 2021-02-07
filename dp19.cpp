#include <bits/stdc++.h>
using namespace std;

//colouring the fence with given k colours and to the n fence.
/*
int coloringways(int n, int k)
{
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[1] = k;
    dp[2] = k * k;

    int mod = 1000000007;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
    return dp[n];
}

int main()
{
    int n = 3;
    int k = 2;
    cout << "no of ways are:" << coloringways(n, k) << "\n";
    return 0;
}*/

long countways(int n, int k)
{
    long total = k;
    int mod = 100000007;

    int same = 0;
    int diff = k;

    for (int i = 2; i <= n; i++)
    {
        same = diff;
        diff = total * (k - 1);
        diff = diff % mod;

        total = (same + diff) % mod;
    }
    return total;
}

int main()
{
    int n = 3;
    int k = 2;
    cout << countways(n, k) << endl;
    return 0;
}