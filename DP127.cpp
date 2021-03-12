#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
double dp[MAX][MAX];

//Maximum average sum partiton of an array.
//Recursive apporach.

/*
double MaxAverageSumUtil(vector<int> &v, int k, int n)
{
    if (dp[n][k] > 0)
    {
        return dp[n][k];
    }
    double sum = 0;
    for (int i = n - 1; i > 0; i--)
    {
        sum += v[i];
        dp[i][k] = max(dp[n][k], MaxAverageSumUtil(v, k - 1, i) + sum / (n - i));
    }
    return dp[n][k];
}

double MaxAverageSum(vector<int> &v, int k)
{
    int n = v.size();
    double sum = 0;
    memset(dp, 0.0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        dp[i + 1][1] = sum / (i + 1);
    }
    return MaxAverageSumUtil(v, k, n);
}

int main()
{
    vector<int> v = {9, 1, 2, 3, 9};
    int k = 3;
    cout << MaxAverageSum(v, k);
    return 0;
}
*/

//O(n^3)

double MaxAverageSum(vector<int> &v, int k)
{
    int n = v.size();

    double dpsum[n + 1];
    dpsum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        dpsum[i+1] = dpsum[i] + v[i];
    }

    double dp[n] = {0};
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = (dpsum[n] - dpsum[i]) / (n - i);
    }

    for (int a = 0; a < k - 1; a++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i] = max(dp[i], (dpsum[j] - dpsum[i]) / (j - i) + dp[j]);
            }
        }
    }
    return dp[0];
}

int main()
{
    vector<int> v = {9, 1, 2, 3, 9};
    int k = 3;
    cout << MaxAverageSum(v, k);
    return 0;
}