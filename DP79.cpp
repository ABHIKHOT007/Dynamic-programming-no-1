#include <bits/stdc++.h>
using namespace std;

//finding the winner of the game.

bool findWinner(int n, int x, int y)
{
    int dp[n + 1];
    dp[0] = false;
    dp[1] = true;

    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 && !dp[i - 1])
        {
            dp[i] = true;
        }
        else if (i - x >= 0 && !dp[i - x])
        {
            dp[i] = true;
        }
        else if (i - y >= 0 && !dp[i - y])
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = true;
        }
    }
    return dp[n];
}

int main()
{
    int n = 5;
    int x = 3;
    int y = 4;
    if (findWinner(n, x, y))
    {
        cout << 'A';
    }
    else
    {
        cout << 'B';
    }
    return 0;
}