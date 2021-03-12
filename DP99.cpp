#include <bits/stdc++.h>
using namespace std;

//Possible decoding of the given strings.
//recursive apporach
/*
int CountDecoding(char *digit, int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (digit[0] == '0')
    {
        return 0;
    }

    int count = 0;

    if (digit[n - 1] > '0')
    {
        count = CountDecoding(digit, n - 1);
    }

    if (digit[n - 1] == '1' || (digit[n - 2] == '2' && digit[n - 1] < '7'))
    {
        count += CountDecoding(digit, n - 2);
    }
    return count;
}

int countWays(char *digit, int n)
{
    if (n == 0 || (n == 1 && digit[0] == '0'))
    {
        return 0;
    }
    return CountDecoding(digit, n);
}

int main()
{
    char digit[] = "1234";
    int n = strlen(digit);
    cout << CountDecoding(digit, n);
    return 0;
}
*/

//o(n^2) apporach.

int countDecoding(char *digit, int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    if (digit[0] == '0')
    {
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        if (digit[i - 1] > '0')
        {
            dp[i] = dp[i - 1];
        }
        if (digit[i - 2] == '1' || (digit[i - 2] == '2' && digit[i - 1] < '7'))
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main()
{
    char digit[] = "1234";
    int n = strlen(digit);
    cout << countDecoding(digit, n);
    return 0;
}