#include<bits/stdc++.h>
using namespace std;

//minimum removals from array
//o(logn)

int findcount(int key, int i, int n, int k, int arr[])
{
    int start,end,mid,ind=-1;
    start=i+1;
    end=n-1;
    while(start<end){
        mid=start+(end-start)/2;
        if(arr[mid]-key<=k){
            ind=mid;
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return ind;
}

int reomval(int arr[], int n, int k)
{
    int i,j,ans=n-1;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        j=findcount(arr[i],i,n,k,arr);
        if(j!=-1){
            ans=min(ans,n-(j-i+1));
        }
    }
    return ans;
}

int main()
{
    int arr[]={1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<reomval(arr,n,k);
    return 0;
}