#include <bits/stdc++.h>
using namespace std;
#define MAX5 100

//O(N*k)

int maximumTralingZeros(int *arr, int n, int k)
{
    int dp[k + 1][MAX5 + 5];
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for (int p = 0; p < n; p++)
    {
        int pw2 = 0;
        int pw5 = 0;

        while (arr[p] % 2 == 0)
        {
            pw2++;
            arr[p] /= 2;
        }
        while (arr[p] % 5 == 0)
        {
            pw5++;
            arr[p] /= 5;
        }

        for (int i = k - 1; i >= 0; i--)
        {
            for (int j = 0; j < MAX5; j++)
            {
                if (dp[i][j] != -1)
                {
                    dp[i + 1][j + pw5] = max(dp[i + 1][j + pw5], dp[i][j] + pw2);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX5; i++)
    {
        ans = max(ans, min(i, dp[k][i]));
    }
    return ans;
}

int main()
{
    int arr[] = {50, 4, 20};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumTralingZeros(arr, n, k);
}