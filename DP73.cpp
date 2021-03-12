#include<bits/stdc++.h>
using namespace std;

//first and last element int he sorted array.

int firstandlast(int arr[], int n, int x)
{
    int first_pos=-1;
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=low-(high-low)/2;
        if(arr[mid]>=x){
            first_pos=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(first_pos==-1||arr[first_pos]!=x){
        return -1;
    }
    return;
}

vector<vector<int>>solve(int arr[], int n,int x)
{
    vector<pair<int,int>> v;
   
    int first_ele=firstandlast(arr,n,x);
    int last_ele=firstandlast(arr,n,x+2)-1;
    v.push_back(make_pair(first_ele,last_ele));
    return v;
}

int main()
{
    int arr[]={12,3,4,5,6,7,3,12,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n,12);
    return 0;
}