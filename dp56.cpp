#include <bits/stdc++.h>
using namespace std;

//maximum sum by breaking number recursively into the three times.
/*
int maxsumByBreaking(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return max((maxsumByBreaking(n / 2) + maxsumByBreaking(n / 3) + maxsumByBreaking(n / 4)), n);
}
*/

int maxSumByBreaking(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i / 2] + dp[i / 3] + dp[i / 4], i);
    }
    return dp[n];
}

int main()
{
    int n = 12;
    cout <<maxSumByBreaking(n);
    return 0;
}