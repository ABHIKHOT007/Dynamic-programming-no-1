#include <bits/stdc++.h>
using namespace std;

//count of ways to make the given number from the 1 3 4 numbers.

int CountWaystomakeNumber(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
    }
    return dp[n];
}

int main()
{
    int n = 10;
    cout << "No of ways to make given number form the 1 & 3 & 4 are:" << CountWaystomakeNumber(n);
    return 0;
}