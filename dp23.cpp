#include <bits/stdc++.h>
using namespace std;

//golomb sequence.
/*
int findgolomb(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return 1 + findgolomb(n - findgolomb(n - 1));
}

void printsolution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << findgolomb(i) << " ";
    }
}
*/

void printsolution(int n)
{
    int dp[n + 1];

    dp[1] = 1;
    cout << dp[1] << " ";

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - dp[i - 1]];
        cout << dp[i] << " ";
    }
}

int main()
{
    int n = 9;
    printsolution(n);
    return 0;
}