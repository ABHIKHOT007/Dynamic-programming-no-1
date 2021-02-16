#include <bits/stdc++.h>
using namespace std;

//Ster's diatomic series.
//o(n)

int Stersseries(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = dp[i / 2];
        }
        else
        {
            dp[i] = dp[(i - 1) / 2] + dp[(i + 1) / 2];
        }
    }
    return dp[n];
}

int main()
{
    int n = 15;
    cout << Stersseries(n);
    return 0;
}
