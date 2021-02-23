#include<bits/stdc++.h>
using namespace std;

//Longest Bitonic sequence.
//o(n^2)

int LongestBitonicSequence(int arr[] ,int n)
{
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }

    //Calculating the longest increasing sequence.
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }

    int LDS[n];
    for(int i=0;i<n;i++){
        LDS[i]=1;
    }

    //Calculating the longest decreasing sequence

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]&&LDS[i]<LDS[j]+1){
                LDS[i]=LDS[j]+1;
            }
        }
    }
    //Calculating the longest Bitonic sequence.

    int max=dp[0]+LDS[0]-1;
    for(int i=1;i<n;i++){
        if(dp[i]+LDS[i]-1>max){
            max=dp[i]+LDS[i]-1;
        }
    }
    return max;
}


int main()
{
    int arr[]= {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Longest Bitonic Sequence is:"<<LongestBitonicSequence(arr,n);
    return 0;
}