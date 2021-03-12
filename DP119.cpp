#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}

int max(int a, int b, int c)
{
    return max(a,max(b,c));
}

int maxProduct(int n)
{
    int dp[n+1];
    dp[0]=dp[1]=0;

    for(int i=1;i<=n;i++){
        int max_val=0;
        for(int j=1;j<=i/2;j++){
            max_val=max(max_val,j*(i-j),j*dp[i-j]);
            dp[i]=max_val;
        }
    }

    return dp[n];
}

int main()
{
    int n=10;
    cout<<maxProduct(n);
    return 0;
}