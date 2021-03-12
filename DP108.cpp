#include <bits/stdc++.h>
using namespace std;

//Count of string that can be formed form the a,b & c in
//the given constrains.
//recursive apporah.

int CountString(int n, int bcount, int ccount)
{
    if (bcount < 0 || ccount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bcount == 0 && ccount == 0)
        return 1;

    int res = CountString(n - 1, bcount, ccount);
    res += CountString(n - 1, bcount - 1, ccount);
    res += CountString(n - 1, bcount, ccount - 1);
    return res;
}

//O(N)

int CountString(int dp[][2][3], int n, int bcount = 1, int ccount = 2)
{
    if (bcount < 0 || ccount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bcount == 0 && ccount == 0)
        return 1;

    if (dp[n][bcount][ccount] != -1)
    {
        return dp[n][bcount][ccount];
    }

    int res = CountString(dp, n - 1, bcount, ccount);
    res += CountString(dp, n - 1, bcount - 1, ccount);
    res += CountString(dp, n - 1, bcount, ccount - 1);

    return (dp[n][bcount][ccount] = res);
}

int followUp(int n)
{
    int dp[n+1][2][3];
    memset(dp,-1,sizeof(dp));
    return CountString(dp,n);
}

int main()
{
    int n = 3;
    cout << CountString(n, 2, 3);
    return 0;
}
