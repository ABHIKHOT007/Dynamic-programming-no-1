#include<bits/stdc++.h>
using namespace std;

//Space optimized solution for the longest common sequence.
//o(n*m) time complexity.
//o(n)space complexity.


int lcs(string &X, string &Y)
{
    int m=X.length();
    int n=Y.length();

    int dp[2][n+1];

    bool flag;
    for(int i=0;i<=m;i++){
        flag=i&1;
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[flag][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                dp[flag][j]=dp[1-flag][j-1]+1;
            }
            else{
                dp[flag][j]=max(dp[1-flag][j],dp[flag][j-1]);
            }
        }
    }
    return dp[flag][n];
}


int main()
{
    string X="AGGTAB";
    string Y="GXTXAYB";

    cout<<"Lenght of the longest common subsequence is:"<<lcs(X,Y)<<"\n";
    return 0;
}