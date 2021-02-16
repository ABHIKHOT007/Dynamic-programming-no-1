#include <bits/stdc++.h>
using namespace std;
//No of ways of tiling the n*4 floor using 1*4 tiles.
//o(n)

int CountOfWaysToFill(int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == 2 || i == 3)
        {
            dp[i] = 1;
        }
        else if (i == 4)
        {
            dp[i] = 2;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 4];
        }
    }
    return dp[n];
}

int main()
{
    int n = 5;
    cout << "No of count to tile floor are:" << CountOfWaysToFill(n);
    return 0;
}