#include <bits/stdc++.h>
using namespace std;

unsigned long long int dp[101][501];

unsigned long long int countREC(int n, int sum)
{
    if (n == 0)
    {
        return sum == 0;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    unsigned long long int ans = 0;

    for (int i = 0; i <= 10; i++)
    {
        if (sum - i >= 0)
        {
            ans += countREC(n - 1, sum - i);
        }
    }

    return dp[n][sum] = ans;
}

unsigned long long int finalCount(int n, int sum)
{
    memset(dp, -1, sizeof(dp));
    unsigned long long int ans = 0;

    for (int i = 1; i <= 9; i++)
    {
        if (sum - i >= 0)
        {
            ans += countREC(n - 1, sum - i);
        }
    }
    return ans;
}

int main()
{
    int n = 3;
    int sum = 5;
    cout << finalCount(n, sum);
    return 0;
}