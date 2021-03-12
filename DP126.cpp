#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 50

//Maximum and minimum values of an algebraic expression.
//O(MAX*MAX*(n+m))

int MinMaxValue(int arr[], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n + m; i++)
    {
        sum += arr[i];
        arr[i] += 50;
    }

    bool dp[MAX + 1][MAX * MAX + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i <= (n + m); i++)
    {
        for (int k = min(n, i + 1); k >= 1; k--)
        {
            for (int j = 0; j < MAX * MAX + 1; j++)
            {
                if (dp[k - 1][j])
                {
                    dp[k][j + arr[i]] = 1;
                }
            }
        }
    }

    int max_value = -INF;
    int min_value = INF;

    for (int i = 0; i < MAX * MAX + 1; i++)
    {
        if (dp[n][i])
        {
            int temp = i - 50 * n;
            max_value = max(max_value, temp * (sum - temp));
            min_value = min(min_value, temp * (sum - temp));
        }
    }
    cout<<max_value<<"\n";
    cout<<min_value<<"\n";
}

int main()
{
    int n=2;
    int m=2;
    int arr[]={1,2,3,4};
    MinMaxValue(arr,n,m);
    return 0;
}