#include <bits/stdc++.h>
using namespace std;

//MAximum tasks to be done.

int max(int x, int y)
{
    return (x > y) ? x : y;
}
/*
int maxTasks(int high[], int low[], int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return max(high[n - 1] + maxTasks(high, low, (n - 2)), low[n - 1] + maxTasks(high, low, (n - 1)));
}
*/
//memoization method.
//o(n^2)

int maxTasks(int high[], int low[], int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=high[0];
    for(int i=2;i<=n;i++){
        dp[i]=max(high[i-1]+dp[i-2],low[i-1]+dp[i-1]);
    }
    return dp[n];
}

int main()
{
    int n = 5;
    int high[] = {3, 6, 8, 7, 6};
    int low[] = {1, 5, 4, 5, 3};
    cout << maxTasks(high, low, n);
    return 0;
}
