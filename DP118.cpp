#include<bits/stdc++.h>
using namespace std;

//MAximum product after cutting of the rod.

int max(int a, int b)
{
    return (a>b)?a:b;
}

int max(int a, int b, int c)
{
    return max(a,max(a,b));
}
/*
int maxProduct(int n)
{
    if(n==0||n==1){
        return 0;
    }

    int max_val=0;
    for(int i=1;i<n;i++){
        max_val=max(max_val,i*(n-i),maxProduct(n-i)*i);
    }
}
*/
int maxProduct(int n)
{
    int dp[n+1];
    dp[0]=dp[1]=0;

    for(int i=1;i<=n;i++){
        int max_val=0;
        for(int j=1;j<=(i/2);j++){
            max_val=max(max_val,(i-1)*j,j*dp[i-1]);
            dp[i]=max_val;
        }
    }
    return dp[n];
}

int main()
{
    cout<<maxProduct(10);
    return 0;
}