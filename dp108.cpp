#include <bits/stdc++.h>
using namespace std;

//Number of ways to arrange the N items of having k colours.
//o(n^2)

int NoWaystoArrange(int N, int k, int arr[])
{
    int brr[N + 1][N + 1];
    int i, j;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                brr[i][j] = 1;
            }
            else
            {
                brr[i][j] = (brr[i - 1][j - 1] + brr[i - 1][j]);
            }
        }
    }

    int dp[k];
    int count = 0;

    dp[0] = 1;

    for (int i = 0; i < k; i++)
    {
        dp[i + 1] = (dp[i] * brr[count + arr[i] - 1][arr[i] - 1]);
        count += arr[i];
    }
    return dp[k];
}

int main()
{
    int N = 4;
    int arr[] = {2, 2};
    int k = sizeof(arr) / sizeof(arr[0]);
    cout << NoWaystoArrange(N, k, arr);
    return 0;
}