#include<bits/stdc++.h>
using namespace std;

//Job scheduling problem.
/*
struct job
{
    int start,finish,profit;
};

bool JobScheduling(job j1, job j2)
{
    return (j1.finish<j2.finish);
}

int NonOverlapping(job arr[], int i)
{
    for(int j=i-1;j>=0;j--){
        if(arr[j].finish<=arr[i-1].finish){
            return j;
        }
    }
    return i;
}

int maxProfit(job arr[], int n)
{
    if(n==1) return arr[n-1].profit;

    int inclProfit=arr[n-1].profit;
    int i=NonOverlapping(arr,n);
    if(i!=-1){
    inclProfit+=maxProfit(arr,i+1);
    }

    int exclProfit=maxProfit(arr,n-1);

    return max(inclProfit,exclProfit);
}

int findmaxProfit(job arr[], int n)
{
    sort(arr,arr+n,JobScheduling);
    return maxProfit(arr,n);
}

int main()
{
    job arr[]={{3,10,20},{1,2,50},{6,19,100},{2,100,200}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr,n);
    return 0;
}
*/

struct job
{
    int start,finish,profit;
};

bool comparator(job j1, job j2)
{
    return (j1.finish<j2.finish);
}

int nonOverlapping(job arr[], int n)
{
    for(int i=n-1;i>=0;i--){
        if(arr[i].finish<=arr[i-1].start){
            return i;
        }
    }
    return -1;
}

int maxprofit(job arr[], int n)
{
    sort(arr,arr+n,comparator);

    int *dp=new int[n];
    dp[0]=arr[0].profit;
    for(int i=1;i<n;i++){
        int inclProfit=arr[i].profit;
        int l=nonOverlapping(arr,i);
        if(l!=-1){
            inclProfit+=dp[l];
        }
        dp[i]=max(inclProfit,dp[i-1]);
    }
    int result=dp[n-1];
    delete dp;
    return result;
}

int main()
{
  job arr[]={{3,10,20},{1,2,50},{6,19,100},{2,100,200}};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<maxprofit(arr,n);
  return 0;
}