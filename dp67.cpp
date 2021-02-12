#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

//minimum cost to fill given weight in bag.
//o(n^2)

int mincostweight(int cost[], int n, int w)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int min_cost = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (j < n)
            {
                min_cost = min(min_cost, cost[j] + dp[i-j-1]);
            }
            dp[i] = min_cost;
        }
    }
    return dp[n];
}

int main()
{
    int arr[] = {20, 10, 4, 50, 100};
    int w = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "minimum cost to fill bag is:" << mincostweight(arr, n, w);
    return 0;
}