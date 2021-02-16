#include <bits/stdc++.h>
using namespace std;

//floor formula

float FindFloor(int N, float p)
{
    double dp[N + 1];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = p;
    dp[3] = 1 - p;
    for (int i = 4; i <= N; i++)
    {
        dp[i] = (p)*dp[i - 2] + (1 - p) * dp[i - 3];
    }
    return dp[N];
}

int main()
{
    int n = 5;
    float p = 0.2;
    cout << FindFloor(n, p);
    return 0;
}