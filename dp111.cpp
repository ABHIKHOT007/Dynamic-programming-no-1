#include<bits/stdc++.h>
using namespace std;

//different ways to form the number m using number n.
//o(n^2)

int DiffWays(int n, int m)
{
    int dp[n+2][n+2];
    memset(dp,0,sizeof(dp));

    dp[0][n+1]=1;

    for(int k=n;k>=m;k--){
        for(int i=0;i<=n;i++){
            dp[i][k]=dp[i][k+1];
            if(i-k>=0){
                dp[i][k]=(dp[i][k]+dp[i-k][k]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int n=3;
    int m=1;
    cout<<DiffWays(n,m);
    return 0;
}