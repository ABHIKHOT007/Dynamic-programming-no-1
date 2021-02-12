#include <bits/stdc++.h>
using namespace std;
#define MAX 100

//maximum difference of zeroes and onces in binary string.

bool allones(string s, int n)
{
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        c += (s[i] == '1');
    }
    return (c == n);
}

int findlength(int arr[], string s, int n, int ind, int st, int dp[][3])
{
    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind][st] != -1)
    {
        return dp[ind][st];
    }

    if (st == 0)
    {
        return dp[ind][st] = max((arr[ind] + findlength(arr, s, n, ind + 1, 1, dp)), findlength(arr, s, n, ind + 1, 0, dp));
    }
    else
    {
        return dp[ind][st] = max(arr[ind] + findlength(arr, s, n, ind + 1, 1, dp), 0);
    }
}

int maxLen(string s, int n)
{
    if (allones(s, n))
    {
        return -1;
    }
    int arr[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        arr[i] = (s[i] == '0' ? 1 : -1);
    }
    int dp[MAX][3];
    memset(dp, -1, sizeof(dp));
    return findlength(arr, s, n, 0, 0, dp);
}

int main()
{
    string s = "11000010001";
    int n = 11;
    cout << maxLen(s, n);
    return 0;
}