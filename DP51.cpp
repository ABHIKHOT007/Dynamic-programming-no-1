#include<bits/stdc++.h>
using namespace std;

//Maximum sum increasing subseuqence.

int maxSumSequence(int arr[], int n)
{
    int max=0;
    int maxSum[n];

    for(int i=0;i<n;i++){
        maxSum[i]=arr[i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
           if(arr[i]>arr[j]&&maxSum[i]<maxSum[j]+arr[i]){
               maxSum[i]=maxSum[j]+arr[i];
           }
        }
    }

    for(int i=0;i<n;i++){
        if(maxSum[i]>max){
            max=maxSum[i];
        }
    }

    return max;
}

int main()
{
    int arr[]={1,101,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumSequence(arr,n);
    return 0;
}