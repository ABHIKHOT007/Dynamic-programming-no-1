#include <bits/stdc++.h>
using namespace std;
#define MAX 100
//maximum trailing zeroe's in the product of the subsrray of size k

int maximumTrailingZeroes(int *arr, int n, int k)
{
    int dp[k + 1][MAX + 5];
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

        for (int i = k - 1; k >= 0; i--)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (dp[i][j] != -1)
                {
                    dp[i + 1][j + pw5] = max(dp[i][j + pw5], dp[i][j] + pw2);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MAX; i++)
    {
        ans = max(ans, min(i, dp[k][i]));
    }
    return ans;
}

int main()
{
    int arr[] = {50, 420};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << maximumTrailingZeroes(arr, n, k);
    return 0;
}