#include <bits/stdc++.h>
using namespace std;

//Longet common subsequence of the given two strings.

int max(int x, int y)
{
    return (x<y)?x:y;
}

//Recursive solution.
/*
int lcs(char *X, char *Y, int m, int n)
{
    if(m==0||n==0){
        return 0;
    }
    if(X[m-1]==Y[n-1]){
        return 1+lcs(X,Y,m-1,n-1);
    }
    return max(lcs(X,Y,m,n-1),(X,Y,m-1,n));
}
*/

int lcs(char *X, char *Y, int m, int n)
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
    return dp[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYAB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of lcs is:" << lcs(X, Y, m, n) << "\n";
    return 0;
}