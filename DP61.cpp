#include<bits/stdc++.h>
using namespace std;

//sum of possible increasing subset of the array.
//o(2^n)
/*
void SubsetSum(int arr[], int n, int sum, int currIndex,unordered_set<int> &s)
{
    if(currIndex>n){
        return;
    }

    if(currIndex==n){
        s.insert(sum);
        return;
    }

    SubsetSum(arr,n,sum+arr[currIndex],currIndex+1,s);
    SubsetSum(arr,n,sum,currIndex+1,s);
}

void printSum(int arr[], int n)
{
    unordered_set<int> s;
    SubsetSum(arr,n,0,0,s);

    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
}

int main()
{
    int arr[]={2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printSum(arr,n);
    return 0;
}
*/

//o(n*sum)
//optimized solution

void printSum(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    bool dp[n+1][sum];
    memset(dp,0,sizeof(dp));
     
     for(int i=0;i<n;i++){
         dp[i][0]=true;
     }

     for(int i=1;i<=n;i++){
         dp[i][arr[i-1]]=true;
         for(int j=1;j<=sum;j++){
             dp[i][j]=true;
             dp[i][j+arr[i-1]]=true;
         }
     }

     for(int j=0;j<=sum;j++){
         if(dp[n][j]==true){
             cout<<j<<" ";
         }
     }
}

int main()
{
    int arr[]={2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printSum(arr,n);
    return 0;
}