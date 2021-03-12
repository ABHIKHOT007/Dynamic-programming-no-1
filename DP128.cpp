#include <bits/stdc++.h>
using namespace std;

//Maximum array elements sum upto the given value ans greater than zero and given number.
//(2^N)

/*
int FindMaxValUtil(int arr[], int n, int num, int maxVal, int ind, int &ans)
{
    if (ind == n)
    {
        ans = max(ans, num);
    }

    if (num - arr[ind] >= 0)
    {
        FindMaxValUtil(arr, n, num - arr[ind], maxVal, ind + 1, ans);
    }
    if (num + arr[ind] <= maxVal)
    {
        FindMaxValUtil(arr, n, num + arr[ind], maxVal, ind + 1, ans);
    }
    return ans;
}

int FindMaxVal(int arr[], int n, int num, int maxVal)
{
    int ans = 0;
    int ind = 0;

    FindMaxValUtil(arr, n, num, maxVal, ind, ans);
    return ans;
}
*/

//O(n*maxval)

int FindMaxVal(int arr[], int n, int num, int maxval)
{
    int ind;
    int val;

    int dp[n][maxval + 1];

    for (int ind = 0; ind < n; ind++)
    {
        for (int val = 0; val <= maxval; val++)
        {
            if (ind == 0)
            {
                if (num - arr[ind] == val || num + arr[ind] == val)
                {
                    dp[ind][val] = 1;
                }
                else
                {
                    dp[ind][val] = 0;
                }
            }
            else
            {
                if (val - arr[ind] >= 0 && val + arr[ind] <= maxval)
                {
                    dp[ind][val] = dp[ind - 1][val - arr[ind]] || dp[ind - 1][val + arr[ind]];
                }
                else if (val - arr[ind] >= 0)
                {
                    dp[ind][val] = dp[ind - 1][val - arr[ind]];
                }
                else if (val + arr[ind] <= maxval)
                {
                    dp[ind][val] = dp[ind - 1][val + arr[ind]];
                }
                else
                {
                    dp[ind][val] = 0;
                }
            }
        }
    }
    for (int val = maxval; val >= 0; val--)
    {
        if (dp[n - 1][val])
        {
            return val;
        }
    }
    return -1;
}

int main()
{
    int num = 1;
    int arr[] = {3, 10, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxval = 15;
    cout << FindMaxVal(arr, n, num, maxval);
    return 0;
}