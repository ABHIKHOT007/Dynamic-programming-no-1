#include<bits/stdc++.h>
using namespace std;

int firstIndexinArray(int arr[], int idx, int n, int x)
{
    //Base case.
    if(idx==n){
        return -1;
    }

    //if the elemet is found at the first index.
    if(arr[idx]==x){
        return idx;
    }

    //otherwise go to the next index in the element array.
    int fiisa=firstIndexinArray(arr,idx+1,n,x);
    return fiisa;
}

int main()
{
    int arr[]={1,2,3,4,5,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"first index of the given elemet is:"<<firstIndexinArray(arr,0,n,5);
    return 0;
}