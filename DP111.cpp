#include <bits/stdc++.h>
using namespace std;

#define V 4

//No of reaching the destination.
//O(V^3) time complexity.
//O(V^3) Auxiliary space .

int countWays(int arr[][V], int u, int v, int k)
{
    int dp[V][V][k + 1];

    for (int c = 0; c <= k; c++)
    {
        for (int a = 0; a < V; a++)
        {
            for (int b = 0; b < V; b++)
            {
                dp[a][b][c] = 0;
                if (a == 0 && a == b)
                {
                    dp[a][b][c] = 1;
                }
                if (c == 1 && arr[a][b])
                {
                    dp[a][b][c] = 1;
                }
                if (c > 1)
                {
                    for (int i = 0; i < V; i++)
                    {
                        if (dp[a][i])
                        {
                            dp[a][b][a] += dp[a][b][c - 1];
                        }
                    }
                }
            }
        }
    }
    return dp[u][v][k];
}

int main()
{
    int arr[V][V] = {{0, 1, 1, 1},
                     {0, 0, 0, 1},
                     {0, 0, 0, 1},
                     {0, 0, 0, 0}};
    int u = 0, v = 3, k = 2;
    cout << countWays(arr, u, v, k);
    return 0;
}