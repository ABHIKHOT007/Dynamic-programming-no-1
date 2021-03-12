#include<bits/stdc++.h>
#define MAX 100
using namespace std;

//MAximum difference of the no of once's ans zeroe's in the given string.
//recursive apporach.

/*
bool allones(string s, int n)
{
    int no=0;
    for(int i=0;i<s.size();i++){
        no+=(s[i]=='1');
    }
    return (no==n);
}

int maxSumofSubset(int arr[],string s,int n, int ind, int st, int dp[][3]){

    if(ind>=n){
        return 0;
    }

    if(dp[ind][st]!=-1){
        return dp[ind][st];
    }

    if(st==0){
        return dp[ind][st]=max(arr[ind]+maxSumofSubset(arr,s,n,ind+1,1,dp),maxSumofSubset(arr,s,n,ind+1,0,dp));
    }
    else{
        return dp[ind][st]=max(arr[ind]+maxSumofSubset(arr,s,n,ind+1,1,dp),0);
    }
}

int maxlength(string s, int n)
{
    if(allones(s,n)){
        return -1;
    }

    int arr[MAX]={0};
    for(int i=0;i<n;i++){
    arr[i]=(s[i]=='1'?1:-1);        
    }

    int dp[MAX][3];
    memset(dp,-1,sizeof(dp));

    return maxSumofSubset(arr,s,n,0,0,dp);
}

int main()
{
    string s="11000010001";
    int n=11;
    cout<<maxlength(s,n);
    return 0;
}
*/

//O(N)
//Using Kadan's algorithm's concept's.
//Change all '0' to the 1 ans ortherwise add -1 to the ans.

int MAXofDiff(string str, int n)
{
    int current_sum=0;
    int max_sum=0;

    for(int i=0;i<n;i++){
        current_sum+=(str[i]=='0'?1:-1);
        if(current_sum<0){
            current_sum=0;
        }

        max_sum=max(max_sum,current_sum);
    }
    return max_sum==0?-1:max_sum;
}

int main()
{
    string s="11000010001";
    int n=11;
    cout<<MAXofDiff(s,n);
    return 0;
}