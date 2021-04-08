#include<bits/stdc++.h>
using namespace std;
/*
int minimumSteps(int arr[], int n)
{
    if(n<=1){
        return 0;
    }

    if(arr[0]==0){
        return 0;
    }

    int maxReachable=arr[0];
    int steps=arr[0];
    int jumps=0;
    for(int i=1;i<=n;i++){
        if(i==n-1){
            return jumps;
        }

        maxReachable=max(maxReachable,arr[i]+i);
        steps--;
        if(steps==0){
            jumps++;
            if(i>maxReachable){
                return -1;
            }
            steps=maxReachable-i;
        }
    }

    return -1;
}   




int minimumSteps(int arr[], int n)
{
    if(n<=1){
        return 0;
    }

    if(arr[0]==0){
        return 0;
    }

    int maxReachable=arr[0];
    int steps=arr[0];
    int jumps=0;

    for(int i=1;i<=n;i++){
        if(i==n-1){
            return jumps;
        }
        maxReachable=max(maxReachable,arr[i]+i);
        steps--;
        if(steps==0){
            jumps++;
            if(i>=maxReachable){
                return -1;
            }
            steps=maxReachable-i;
        }
    }
    return -1;
}




int main()
{
     int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<minimumSteps(arr,n);
    return 0;
}*/