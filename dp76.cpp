#include<bits/stdc++.h>
using namespace std;

//no of time of operations on character
//o(n)

int minOperation(int n, int insert, int remove, int copy)
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return insert;
    }

    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[1]=insert;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=min(dp[i-1]+insert,dp[i/2]+copy);
        }
        else{
            dp[i]=min(dp[i-1]+insert,dp[(i+1)/2]+copy+remove);
        }
    }
    return dp[n];
}

int main()
{
    int n=9;
    int insert=1;
    int remove=2;
    int copy=1;
    cout<<minOperation(n,insert,remove,copy);
    return 0;
}