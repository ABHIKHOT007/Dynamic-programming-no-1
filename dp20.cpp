#include <bits/stdc++.h>
using namespace std;
//newman shanks williams prime algo.
/*
int newman(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return 2 * newman(n - 1) + newman(n - 2);
}*/

/*
int newman(int n)
{
    int dp[n+1];

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}*/

int newman(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int a = 1;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        int c = 2 * b + a;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n = 3;
    cout << "newman count is:" << newman(n) << "\n";
    return 0;
}