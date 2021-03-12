#include <bits/stdc++.h>
using namespace std;

//cout no of ways to reach destination from the given source.
//recursive solution

#define V 4

int CountNoofWays(int arr[][V], int u, int v, int k)
{
    if (v == u || k == 0)
    {
        return 1;
    }
    if (k == 1 && arr[u][v]!=0)
    {
        return 1;
    }
    if (k <= 0)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (arr[u][i] == 1)
        {
            count += CountNoofWays(arr, i, v, k - 1);
        }
    }
    return count;
}

int main()
{
    int arr[V][V] = {{0, 1, 1, 1},
                     {0, 0, 0, 1},
                     {0, 0, 0, 1},
                     {0, 0, 0, 0}};
    int u = 0, v = 3, k = 2;
    cout << CountNoofWays(arr, u, v, k);
    return 0;
}