#include<bits/stdc++.h>
const int MAX =100;
int inf=2e9;
using namespace std;

int dp[MAX][MAX];

//Non-decresing subsequence of k size.

void initalize()
{
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j]=-1;
        }
    }
}

int solve(int arr[], int n, int k)
{
    if(dp[n][k]!=-1){
        return -1;
    }

    if(n<0){
        return inf;
    }

    if(k==1){
        int ans=inf;
        for(int i=0;i<n;i++){
            ans=min(ans,arr[i]);
        }
        return ans;
    }

    int ans=inf;
    for(int i=0;i<n;i++){
        if(arr[i]>=arr[n]){
            ans=min(ans,min(solve(arr,i,k),solve(arr,i,k-1))+arr[n]);
        }
        else{
            ans=min(ans,solve(arr,n,k));
        }
    }

    dp[n][k]=ans;
    return dp[n][k];
}


int main()
{
    int arr[]={58,12,11,12,82,30,2,77,16,86};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<solve(arr,n,k);
    return 0;
}
