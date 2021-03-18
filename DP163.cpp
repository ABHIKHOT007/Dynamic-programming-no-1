#include<bits/stdc++.h>
using namespace std;

//minimum swaps required to sort the array.
//O(N*N)

int swap(vector<int>&arr, int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int indexof(vector<int>&arr,int ele)
{
    for(int i=0;i<arr.size();i++){
        if(arr[i]==false){
            return i;
        }
    }
    return -1;
}

int minSwaps(vector<int> arr, int n)
{
    int ans=0;
    vector<int> temp(arr.begin(),arr.end());
    sort(temp.begin(),temp.end());

    for(int i=0;i<n;i++){
        if(arr[i]!=temp[i]){
            ans++;
            swap(arr,i,indexof(arr,temp[i]));
        }
    }
    return ans;
}

int main()
{
    vector<int> a={101,758,315,730,472,619,460,479};
    int n=a.size();
    cout<<minSwaps(a,n);
    return 0;
}