#include<bits/stdc++.h>
using namespace std;

//First index of the given element int he array.
//o(logn)

int FirstIndex(int arr[], int n, int target)
{
    int L=0;
    int R=n-1;
    int ans=-1;

    while(L<=R){
        int mid=L+(R-L)/2;
        if(arr[mid]>=target){
            ans=mid;;
            R=mid-1;
        }
        else{
            L=mid+1;
        }
    }

    return ans;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    cout<<FirstIndex(arr,n,target);
    return 0;
}