#include<bits/stdc++.h>
using namespace std;

//longest palidromic substring.
//recursive solution.

int max(int x, int y)
{
    return (x>y)?x:y;
}

/*
int LongestPalidromicString(char *arr, int i, int j)
{
    if(i==j){
        return 1;
    }
    if(arr[i]==arr[j]&&i+1==j){
        return 2;
    }
    if(arr[i]==arr[j]){
        return LongestPalidromicString(arr,i+1,j-1)+2;
    }
    return max(LongestPalidromicString(arr,i,j-1),LongestPalidromicString(arr,i+1,j));
}

int main()
{
    char arr[]="GEEKFORKEEKS";
    int n=strlen(arr);
    cout<<"Longest palidromic substring is:"<<LongestPalidromicString(arr,0,n-1);
    return 0;
}
*/

int LongestPalidromicSubstring(char *arr)
{
    int n=strlen(arr);
    int dp[n][n];

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i-l-1;
            if(arr[i]==arr[j]&&l==2){
                dp[i][j]=2;
            }
            else if(dp[i]==dp[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    char arr[]="GEEKFORGEEKS";
    cout<<LongestPalidromicSubstring(arr);
    return 0;
}