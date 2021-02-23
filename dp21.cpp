#include<bits/stdc++.h>
using namespace std;

//maximum revenue from the billboards placed on the road of length m miles.

int maxRevenue(int m, int arr[], int revenue[], int n, int t)
{
    int dp[m+1];
    memset(dp,0,sizeof(dp));
    int nextbb=0;

    for(int i=1;i<=m;i++){
        //if all billboards are already placed in maximum profit order.
        //otherwise.
        if(nextbb<n){

            if(arr[nextbb]!=i){
                dp[i]=dp[i-1];
            }
            else{
                //if it the last billboard remained.

                if(i<=t){
                    dp[i]=max(dp[i-1],revenue[nextbb]);
                }
                else{
                    dp[i]=max(dp[i-t-1]+revenue[nextbb],dp[i-1]);
                }
                nextbb++;
            }
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp[m];
}

int main()
{
    int m=20;
    int arr[]={6,7,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int t=5;
    int revenue[]={5,6,5,3,1};
    cout<<maxRevenue(m,arr,revenue,n,t);
    return 0;
}