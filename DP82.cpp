#include <bits/stdc++.h>
#define MAX 100
using namespace std;

//recursive apporach.
//Expoential time complexity.
/*
int CountTurnPath(int m, int n, int k)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (k == 0)
    {
        return 0;
    }

    if (k == 1)
    {
        return 2;
    }

    return CountTurnPath(m, n + 1, k - 1) + CountTurnPath(m + 1, n, k - 1);
}

int main()
{
    int m = 3;
    int n = 3;
    int k = 1;
    cout <<"Total no of path with maximum k number of jumps:"<<CountTurnPath(m, n, k);
    return 0;
}
*/

int dp[MAX][MAX][MAX][2];

int CountTurnPath(int i, int j, int k, int d)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (k == 0)
    {
        if (d == 0 && i == 0)
        {
            return 1;
        }
        if (d == 1 && j == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][j][k][d] != -1)
    {    
        return dp[i][j][k][d];
    }

    if (d == 0)
    {
        return dp[i][j][k][d] = CountTurnPath(i, j - 1, k, d) + CountTurnPath(i - 1, j, k - 1, !d);
    }

    return dp[i][j][k][d] = CountTurnPath(i - 1, j, k, d) + CountTurnPath(i, j - 1, k - 1, !d);
}

int CountPath(int i, int j, int k)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }

    memset(dp, -1, sizeof(dp));

    return CountTurnPath(i - 1, j, k - 1, d) + CountPath(i, j - 1, k, 0);
}

int main()
{
    int m = 3;
    int n = 3;
    int k = 2;
    cout << "Number of path are:" << CountPath(m - 1, n - 1, k);
    return 0;
}