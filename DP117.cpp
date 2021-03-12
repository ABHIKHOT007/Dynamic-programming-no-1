#include <bits/stdc++.h>
using namespace std;

//countof N digit numbers that difference between sum of even and odd digits is one.

unsigned long long int dp[50][1000][1000][2];

unsigned long long int CountREC(int digit, int esum, int osum, int isOdd, int n)
{
    if (digit == n)
    {
        return (esum - osum == 1);
    }

    if (dp[digit][esum][osum][isOdd] != -1)
    {
        return dp[digit][esum][osum][isOdd];
    }

    unsigned long long int ans = 0;

    if (isOdd)
    {
        for (int i = 0; i <= 9; i++)
        {
            ans += CountREC(digit + 1, esum, osum + i, false, n);
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            ans += CountREC(digit + 1, esum + i, osum, true, n);
        }
    }

    return dp[digit][esum][osum][isOdd] = ans;
}

unsigned long long int finalCount(int n)
{
    int digit = 0;
    memset(dp, -1, sizeof(dp));
    unsigned long long int ans = 0;

    int esum = 0;
    int osum = 0;

    for (int i = 1; i <= 9; i++)
    {
        ans += CountREC(digit + 1, esum + i, osum, true, n);
    }
    return ans;
}

int main()
{
    int n = 3;
    cout << finalCount(n);
    return 0;
}