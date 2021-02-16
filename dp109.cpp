#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

//floor function.

int dp[MAX];

void initdp()
{
    for (int i = 0; i < MAX; i++)
    {
        dp[i] = -1;
    }
}

int func(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (dp[x] == -1)
    {
        dp[x] = x + func(x / 2);
    }
    return dp[x];
}

void printsolution(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << func(arr[i]);
    }
    cout << "\n";
}

int main()
{
    initdp();
    int arr[] = {8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printsolution(arr, n);
    return 0;
}