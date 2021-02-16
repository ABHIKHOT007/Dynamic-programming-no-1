#include<bits/stdc++.h>
using namespace std;

//count no of ways to make array of size n using the given conditions having every element ibetween the 1 to x & k.
int countWays(int n, int k, int x)
{
    int dp[110];

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<n;i++){
        dp[i]=(k-2)*dp[i-1]+(k-1)*dp[i-2];
    }
    return (x==1)?(k-1)*dp[n-2]:dp[n-1];
}

int main()
{
    int n=4;
    int k=3;
    int x=2;
    cout<<countWays(n,k,x);
    return 0;
}