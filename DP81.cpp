#include<bits/stdc++.h>
using namespace std;

/*
int SubArrayCount(int arr[], int n)
{
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]+=dp[j];
            }
        }
    }

    int count_no=0;
    for(int i=0;i<n;i++){
        count_no+=dp[i];
    }
    return count_no;
}
*/
//Time complexity o(n).
// space complexity o(1).

int SubArrayCount(int arr[], int n)
{
    int count[10]={0};

    for(int i=0;i<n;i++){
        for(int j=arr[i]-1;j>=0;j--){
            count[arr[i]]+=count[j];
        }
        count[arr[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=count[i];
    }
    return ans;
}


int main()
{
    int arr[]={3,2,4,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<SubArrayCount(arr,n);
    return 0;
}