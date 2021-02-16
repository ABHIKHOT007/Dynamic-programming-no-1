#include <bits/stdc++.h>
using namespace std;

//counting no of ways of paring the patricipants.
/*
int NoofWays(int n)
{
    if(n==0||n==1){
        return 1;
    }
    else{
        return NoofWays(n-1)+(n-1)*NoofWays(n-2);
    }

}
*/

int NoofWays(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 3;
    cout << NoofWays(n);
    return 0;
}
