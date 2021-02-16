#include <bits/stdc++.h>
using namespace std;

//countning total no of ways of forming the given number N from element of the array.
//o(n^2)

int NoofWaysToformNumber(int arr[], int n, int N)
{
    int dp[N + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= arr[j])
            {
                dp[i] += dp[i - arr[j]];
            }
        }
    }
    return dp[N];
}

int main()
{
    int arr[] = {12, 3, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int N = 14;
    cout << "no of ways to form the given nunber using elememts of the given array are:/n" << NoofWaysToformNumber(arr, n, N);
    return 0;
}