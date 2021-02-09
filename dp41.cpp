#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// maximum sum of the increasing subsequence such that kth index must be included necessarily and element till ith index.
//o(n^2)
/*
ll maxSum(ll a[], ll n, ll index, ll k)
{
    ll dp[n][n] = {0};

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[0])
        {
            dp[0][i] = a[i] + a[0];
        }
        else
        {
            dp[0][i] = a[i];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i] && j > i)
            {
                if (dp[i - 1][i] + a[j] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][i] + a[j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[index][k];
}

int main()
{
    ll a[] = {1, 101, 2, 3, 100, 4, 5};
    ll n = sizeof(a) / sizeof(a[0]);
    ll index = 4;
    ll k = 6;
    cout << "maximum sum of the increasing subsequence is:" << maxSum(a, n, index, k);
    return 0;
}
*/

//o(index^2)

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSum(int a[], int n, int index, int k)
{
    if (index >= k)
    {
        return -1;
    }

    int dp[index] = {0};
    int i;

    for (int i = 0; i <= index; i++)
    {
        dp[i] = a[i];
    }

    int max_sum = INT_MIN;

    for (int i = 0; i <= index; i++)
    {
        if (a[i] >= a[k])
        {
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = dp[j] + a[i];
            }
            max_sum = max(max_sum, dp[i]);
        }
    }
    if (max_sum == INT_MIN)
    {
        return a[k];
    }

    return max_sum + a[k];
}

int main()
{
    int a[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int index = 4;
    int k = 6;
    cout << "maximum sum of the subsequence is:" << maxSum(a, n, index, k);
    return 0;
}