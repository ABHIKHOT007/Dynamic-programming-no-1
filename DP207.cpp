#include<bits/stdc++.h>
using namespace std;

int arr[105];
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        if(k>(n-1)/2){
            puts("-1"); continue;
        }
        int x=n;
        for(int i=1;i<=n;i++) arr[i]=0;

        for(int i=2;i<n;i+=2){
            if(x<=n-k) break;
            arr[i]=x--;
        }
        x=1;

        for(int i=1;i<=n;i++){
            if(arr[i]) continue;
            arr[i]=x++;
        }

        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}