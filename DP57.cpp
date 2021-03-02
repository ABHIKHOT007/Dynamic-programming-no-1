#include<bits/stdc++.h>
using namespace std;

//Printing the elements of the longest increasing cosecutive subsequence.
//o(n)


int PrintSequence(int arr[], int n)
{
    unordered_map<int,int> hash;
    int dp[n];
    memset(dp,0,sizeof(dp));

    int max_len=INT_MIN;

    int index=-1;
    for(int i=0;i<n;i++){
        if(hash.find(arr[i]-1)!=hash.end()){
            int index=hash[arr[i]-1]-1;
            dp[i]=1+dp[index];
        }
        else{
            dp[i]=1;
        }
        hash[arr[i]]=i+1;

        if(max_len<dp[i]){
            max_len=dp[i];
            index=i;
        }
    }
    for(int j=arr[index]-max_len+1;j<=arr[index];j++){
        cout<<j<<" ";
    }
}

int main()
{
    int arr[]={3,10,3,11,4,5,6,7,8,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<PrintSequence(arr,n);
    return 0;
}