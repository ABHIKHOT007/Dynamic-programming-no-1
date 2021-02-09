#include <bits/stdc++.h>
using namespace std;

int productofsequence(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (arr[j - 1] <= i && arr[j - 1] > 0)
            {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
            }
        }
    }
    return dp[k][n];
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    int k = 10;
    cout << "No of sequences are:" << productofsequence(v, k);
    return 0;
}