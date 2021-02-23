#include<bits/stdc++.h>
using namespace std;
//printing partition subsets.
//o(n^2)

void printsets(vector<int> set1, vector<int> set2)
{
    
    for(int i=0;i<set1.size();i++){
        cout<<set1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<set2.size();i++){
        cout<<set2[i]<<" ";
    }
}

bool findpartition(int arr[],int n, vector<int> &set1, vector<int> &set2, int sum1, int sum2, int pos)
{
    if(pos==n){
        if(sum1==sum2){
            printsets(set1,set2);
            return true;
        }
        else{
            return false;
        }
    }
    set1.push_back(arr[pos]);
    bool res=findpartition(arr,n,set1,set2,sum1+arr[pos],sum2,pos+1);

    if(res){
        return res;
    }

    set1.pop_back();
    set2.push_back(arr[pos]);
    res=findpartition(arr,n,set1,set2,sum1,sum2+arr[pos],pos+1);
    if(res==false){
        if(!set2.empty()){
            set2.pop_back();
        }
    }
    return res;
}

bool isPartiton(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    if(sum%2!=0){
        return false;
    }

    vector<int> set1,set2;

    return findpartition(arr,n,set1,set2,0,0,0);
}

int main()
{
    int arr[]={5,5,1,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(isPartiton(arr,n)){
        cout<<"-1";
    }
    return 0;
}