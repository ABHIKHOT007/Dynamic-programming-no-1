#include<bits/stdc++.h>
using namespace std;
//Longest bitonic sequence.
//o(n^2)

void printSolution(vector<int>& arr, int size)
{
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void printLongestBitionicSequence(int arr[], int n)
{
    vector<vector<int>> v1(n);
    v1[0].push_back(arr[0]);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j] && v1[i].size()>v1[j].size()){
                v1[i]=v1[j];
            }
        }
        v1[i].push_back(arr[i]);
    }

    vector<vector<int>> v2(n);

    v2[0].push_back(arr[n-1]);

    for(int i=n-1;i>0;i--){
        for(int j=n-2;j>i;j--){
            if(arr[i]>arr[j]&&v2[i].size()<v2[j].size()){
                v2[i]=v2[j];
            }
        }
        v2[i].push_back(arr[i]);
    }

    for(int i=0;i<n;i++){
        reverse(v2[i].begin(),v2[i].end());
    }
    int max=0;
    int maxIndex=-1;

    for(int i=0;i<n;i++){
        if(v1[i].size()+v1[i].size()-1>max){
            max=v1[i].size()+v1[i].size()-1;
        }
    }

    printSolution(v1[maxIndex],v1[maxIndex].size()-1);
    printSolution(v2[maxIndex],v2[maxIndex].size());
}

int main()
{
    int arr[]={1,11,2,10,4,5,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printLongestBitionicSequence(arr,n);
    return 0;
}
