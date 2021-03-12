#include<bits/stdc++.h>
using namespace std;

//Longest common sub_sequence lexicographical order

void lcs(char *X, char *Y, int m, int n)
{
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int len=dp[m][n];
    char lcs[len+1];
    lcs[len]='\0';
    int i=m;
    int j=n;

    while(i>=0&&j>=0){
        if(X[i-1]==Y[j-1]){
            lcs[len-1]=X[i-1];
            i--;
            j--;
            len--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<lcs;
}

int main()
{
    char X[]="AGGTAB";
    char Y[]="GXTXYAB";
    int m=strlen(X);
    int n=strlen(Y);
    lcs(X,Y,m,n);
    return 0;
}