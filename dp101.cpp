#include <bits/stdc++.h>
#define MAX 50
using namespace std;

//removing element from array to get maximum product of the elements.

int maxProduct(int dp[][MAX], int arr[], int low, int high, int ele)
{
    if (low == high)
    {
        return arr[low] * ele;
    }
    if (dp[low][high])
    {
        return dp[low][high];
    }
    dp[low][high] = max(arr[low] * ele + maxProduct(dp, arr, low + 1, high, ele + 1), arr[high] * ele + maxProduct(dp, arr, low, high - 1, ele + 1));
    return dp[low][high];
}
int main()
{
    int arr[] = {1, 3, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[MAX][MAX];
    memset(dp, 0, sizeof(dp));
    cout << maxProduct(dp, arr, 0, n - 1, 1);
    return 0;
}