#include <bits/stdc++.h>
using namespace std;

//Countin all possible palidromic substring of the given string.

int n,dp[1000][1000];
string str="abcd";

//o(n^2)

int CountPalidromeString(int i, int j)
{
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==j){
        return dp[i][j]=1;
    }
    else if(str[i]==str[j]){
        return dp[i][j]=CountPalidromeString(i+1,j)+CountPalidromeString(i,j-1);
    }
    else{
        return dp[i][j]=CountPalidromeString(i+1,j)+CountPalidromeString(i,j-1)-CountPalidromeString(i+1,j-1);
    }
}

int main()
{
   memset(dp,-1,sizeof(dp));
   n=str.length();
    cout << CountPalidromeString(0,n-1);
    return 0;
}