#include<bits/stdc++.h>
using namespace std;

int minimumJumps(int arr[], int n)
{
    if(n<=1){
        return 1;
    }

    if(arr[0]==0){
        return 0;
    }

    int maxReachable=arr[0];
    int steps=arr[0];
    int jumps=1;

    for(int i=1;i<n;i++){
        maxReachable=max(maxReachable,arr[i]+1);
        steps--;
        if(i==n-1){
            return jumps;
        }

        if(steps==0){
            jumps++;
            if(i>=maxReachable){
                return -1;
            }
            steps=i-maxReachable;
        }
    }
    return -1;
}


int main()
{
    int arr[]={1,3,5,8,9,2,6,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minimumJumps(arr,n);
    return 0;
}