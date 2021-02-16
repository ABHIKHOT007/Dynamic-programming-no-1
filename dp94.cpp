#include <bits/stdc++.h>
using namespace std;

//count no of ways of tiling the given of size n*m using 1*m size of tiles.
//o(n)

int CountWaysofTiling(int n, int m)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > m)
        {
            dp[i] = dp[i - 1] + dp[i - m];
        }
        else if (i < m || i == 1)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 2;
        }
    }
    return dp[n];
}

int main()
{
    int n = 7;
    int m = 4;
    cout << CountWaysofTiling(n, m);
    return 0;
}