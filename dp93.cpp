#include <bits/stdc++.h>
using namespace std;
//count ways to divide the circle using n non-intersecting chords.

int CountChords(int n)
{
    int N = 2 * n;
    int dp[N + 1] = {0};
    dp[0] = 1;
    dp[2] = 1;
    for (int i = 4; i <= N; i += 2)
    {
        for (int j = 0; j <= i - 1; j += 2)
        {
            dp[i] += dp[j] * dp[i - 2 - j];
        }
    }
    return dp[N];
}

int main()
{
    int n = 2;
    cout << CountChords(n);
    return 0;
}