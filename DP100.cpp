#include<bits/stdc++.h>
using namespace std;

//Count no of ways to patition the givem set into the k subsets.
//o(2^n)
/*
int CountPartitionWays(int n, int k)
{
    if(n==0||k==0||k>n){
        return 0;
    }

    if(k==1||k==n){
        return 1;
    }

    return k*CountPartitionWays(n-1,k)+CountPartitionWays(n-1,k-1);
}
*/

int CountPartitionWays(int n, int k)
{
    int dp[n+1][k+1];

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1||i==1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int n=3;
    int k=2;
    cout<<CountPartitionWays(n,k);
    return 0;
}