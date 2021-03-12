#include <bits/stdc++.h>
using namespace std;

//minimum number of coins required to make given value.
/*
int minCoins(int arr[], int n, int v)
{
    if(v==0){
        return 0;
    }

    int res=INT_MAX;

    for(int i=0;i<n;i++){
        if(arr[i]<=v){
            int sub_res=minCoins(arr,n,v-arr[i]);
            if(sub_res!=INT_MAX&&sub_res+1<res){
                res=sub_res+1;
            }
        }
    }
    return res;
}
*/

int minCoins(int arr[], int n, int v)
{
    int dp[v + 1];
    dp[0] = 0;

    for (int i = 1; i <= v; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= i)
            {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                {
                    dp[i] = sub_res + 1;
                }
            }
        }
        if (dp[v] == INT_MAX)
        {
            return -1;
        }
        return dp[v];
    }
}

int main()
{
    int arr[] = {9, 6, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int v = 11;
    cout << minCoins(arr, n, v);
    return 0;
}
