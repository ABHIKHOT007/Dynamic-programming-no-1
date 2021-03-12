#include<bits/stdc++.h>
using namespace std;

//o(n)

void countWays(int arr[], int n)
{
    int count_jumps[n];
    memset(count_jumps,0,sizeof(count_jumps));

    for(int i=n-2;i>=0;i--){
        if(arr[i]>=n-i-1){
            count_jumps[i]++;
        }
        for(int j=i+1;j<n-1&&j<=arr[i]+i;j++){
            if(count_jumps[j]!=-1){
                count_jumps[i]+=count_jumps[j];
            }
        }
        if(count_jumps[i]==0){
            count_jumps[i]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<count_jumps[i]<<" ";
    }
}

int main()
{
    int arr[]={1,3,5,8,9,1,0,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    countWays(arr,n);
    return 0;
}