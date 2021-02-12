#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
/*
int min(int x, int y, int z);

int mincost(int cost[R][C], int m, int n)
{
    int i, j;

    int tc[R][C];
    tc[0][0] = cost[0][0];

    for (int i = 1; i <= m; i++)
    {
        tc[i][0] = tc[i - 1][0] + cost[i][0];
    }
    for (int j = 1; j <= n; j++)
    {
        tc[0][j] = tc[0][j - 1] + cost[0][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];
        }
    }
    return tc[m][n];
}

int min(int x, int y, int z)
{
    if (x < y)
    {
        return (x < z) ? x : z;
    }
    else
    {
        return (y < z) ? y : z;
    }
}

int main()
{
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};
    cout <<mincost(cost, 2, 2);
    return 0;
}
*/
int mincost(int cost[R][C])
{
    for (int i = 1; i < R; i++)
    {
        cost[i][0] += cost[i - 1][0];
    }
    for (int j = 1; j < C; j++)
    {
        cost[0][j] += cost[0][j - 1];
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            cost[i][j] += min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
        }
    }
    return cost[R - 1][C - 1];
}

int main()
{
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};
    cout<< mincost(cost);
    return 0;
}