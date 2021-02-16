#include <bits/stdc++.h>
using namespace std;

//Unique path in a grid with obstacels.

int Uniqueuepath(vector<vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));

    if (v[0][0] == 0)
    {
        dp[0][0] = 1;
    }

    for (int i = 1; i < r; i++)
    {
        if (v[i][0] == 0)
        {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int j = 1; j < r; j++)
    {
        if (v[0][j] == 0)
        {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (v[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[r - 1][c];
}

int main()
{
    vector<vector<int>> v = {{0, 0, 0},
                             {0, 1, 0},
                             {0, 0, 0}};

    cout << Uniqueuepath(v) << " \n";
}
