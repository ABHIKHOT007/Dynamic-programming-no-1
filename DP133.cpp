#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 1001
#define INF -11111111
//maximum sumof the subarray of m*n.
//O(M^2N)

int maxSum(int arr[][N])
{
    int dp[N][M];
    int curr[M];
    int maxsum[M];
    memset(dp, -1, sizeof(dp[0][0] * N * M));
    curr[0] = 0;
    dp[0][0] = 0;

    for (int i = 1; i <= 5; i++)
    {
        int len = arr[i - 1][0];

        for (int j = 1; j <= len; j++)
        {
            curr[j] = arr[i - 1][j];
            curr[j] += curr[j - 1];
            maxsum[j] = INF;
        }
        for (int j = 1; j <= len && j <= 6; j++)
        {
            for (int k = 1; k <= len; k++)
            {
                if (j + k - 1 <= len)
                {
                    maxsum[j] = max(maxsum[j], curr[j + k - 1] - curr[k - 1]);
                }
            }
        }

        for (int j = 0; j <= 6; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = 1; j <= 6; j++)
        {
            for (int curr = 1; curr <= j && curr <= len; curr++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - curr] + maxsum[curr]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 6; i++)
    {
        ans = max(ans, dp[5][i]);
    }
    return ans;
}

int main()
{
    int arr[][N] = {{3, 2, 3, 5},
                    {2, 7, -1},
                    {2, 8, 10},
                    {4, 5, 2, 6, 1},
                    {3, 2, 3, -2}};
    cout << maxSum(arr);
    return 0;
}