#include <bits/stdc++.h>
using namespace std;

//maximum dot product of the given two array elements.
//O(N)

long long int dp[509][509];

long long int maxDotProduct(vector<int> &v1, vector<int> &v2, int i, int j, int flag = 0)
{
    if (v1.size() == i || v2.size() == j)
    {
        return flag = 0 ? INT_MIN : 0;
    }

    long long int ans = (v1[i] * v2[i]) + maxDotProduct(v1, v2, i + 1, j + 1, 1);
    ans = max(ans, maxDotProduct(v1, v2, i + 1, j, flag));
    ans = max(ans, maxDotProduct(v1, v2, i, j + 1, flag));
    ans = max(ans, maxDotProduct(v1, v2, i + 1, j + 1, flag));

    return ans;
}

int main()
{
    memset(dp, 0, sizeof(dp));

    vector<int> v1 = {2, 1, -2, 5};
    vector<int> v2 = {3, 0, 6};
    cout << maxDotProduct(v1, v2, 0, 0, 0);
    return 0;
}