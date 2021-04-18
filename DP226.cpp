#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=100000007;
const double eps=1e-9;

int arr[1000002];
ll cf[10000002];

void solve()
{       
    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=10000000;j+=i){
            cf[j]+=i;
        }
        if(cf[i]<=10000000){
            if(arr[cf[i]]==0){
                arr[cf[i]]=i;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

}   

int main()
{
    solve();
    return 0;
}
/*
int main()
{
    #ifdef fisier
           ifstream cin("input.in");
           ifstream.cout("output.out");
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(arr[n]==0){
            cout<<"-1\n";
        }
        else{
            cout<<arr[n]<<"\n";
        }
    }
    return 0;
}*/