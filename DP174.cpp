#include<bits/stdc++.h>
using namespace std;
/*
int coinChamgeCombination(vector<int> v, int n, int s)
{
    int dp[s+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;

    for(int i=0;i<n;i++){
        for(int j=v[i];j<=s;j++){
            dp[j]+=dp[j-v[i]];
        }
    }

    return dp[s];
}
*/

int coinChangePermutation(vector<int> v, int n, int s)
{
    int dp[s+1];
    memset(dp,0,sizeof(dp));

    dp[0]=1;

    for(int i=0;i<n;i++){
        for(int j=1;j<=s;j++){
            if(arr[j]<=i){
                dp[i]=(long))dp[i]+;; vonpdrt
            }
        }
    }
}

int main()
{
    vector<int> v={1,2,3};
    int s=4;
    int n=v.size();
    cout<<coinChangePermutation(v,n,s);
    return 0;
}