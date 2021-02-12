#include<bits/stdc++.h>
using namespace std;

//maximumizing the sum of the array so that it can be empty.

int maxiize(int arr[], int n)
{
    unordered_map<int,int> hash;

    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    int maxi=*max_element(arr,arr+n);
    for(int i=2;i<maxi;i++){
        hash[i]=max(hash[i-1],hash[i-2]+hash[i]*i);
    }
    return hash[maxi];
}

int main()
{
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxiize(arr,n);
    return 0;
}