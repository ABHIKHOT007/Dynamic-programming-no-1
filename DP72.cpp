#include<bits/stdc++.h>
#define MAX 10
using namespace std;

//o(nmk).


int LCS(int dp[MAX][MAX][MAX], int arr1[], int arr2[], int n, int m, int k)
{
    if(n<0){
        return -1;
    }

    int ans=dp[n][m][k];

    if(n<0||m<0){
        return 0;
    }

    if(ans!=-1){
        return ans;
    }

    ans=max(LCS(dp,arr1,arr2,n-1,m,k),LCS(dp,arr1,arr2,n,m-1,k));

    return ans;
}

int main()
{
    int k=1;
    int arr1[]={1,2,3,4,5};
    int arr2[]={5,3,1,4,2};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);

    int dp[MAX][MAX][MAX];
    memset(dp,-1,sizeof(dp));

    cout<<LCS(dp,arr1,arr2,n,m,k) ;
    return 0;
}