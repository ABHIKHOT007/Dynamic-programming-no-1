#include <bits/stdc++.h>
using namespace std;
//counting ways to reach the origin.
//recursive apporach
/*
int countways(int n, int m)
{
    if(n==0||m==0){
        return 1;
    }
    return countways(n-1,m)+countways(n,m-1);
}*/

int countways(int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][m];
}

int main()
{
    int n = 3;
    int m = 6;
    cout << countways(n, m);
    return 0;
}