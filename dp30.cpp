#include<bits/stdc++.h>
using namespace std;

//printing the longest palidromic string.
//o(n^2)

string lps(string &x, string &y)
{
    int m=x.length();
    int n=y.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int len=dp[m][n];
    string str(len+1,'\0');

    int i=m;
    int j=n;
    while(i>0&&j>0){
        if(x[i-1]==y[j-1]){
            str[len-1]=x[i-1];
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
    return str;
}

string longestpalidromicstring(string &str)
{
    string res=str;
    reverse(res.begin(),res.end());
    return lps(str,res);
}
int main()
{
    string str="GEEKFORGEKS";
    cout<<longestpalidromicstring(str);
    return 0;
}