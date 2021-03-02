#include<bits/stdc++.h>
using namespace std;

//Constructing the longest increasing subsequence.
//o(n^2)

void printLIS(vector<int>& arr)
{
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

void consturctLIS(int arr[], int n)
{
    vector<vector<int>> dp(n);
    dp[0].push_back(arr[0]);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i].size()<dp[j].size()+1){
                dp[i]=dp[j];
            }
        }
        dp[i].push_back(arr[i]);
    }
    vector<int> max=dp[0];

    for(vector<int> x:dp){
        if(x.size()>max.size()){
            max=x;
        }
    }

    printLIS(max);
}

int main()
{
    int arr[]={3,2,6,4,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    consturctLIS(arr,n);
    return 0;
}