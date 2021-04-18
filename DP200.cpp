#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];       
    }

    int ans=a[0];
    if(a[1]==a[2]){
        ans=a[1];
    }

    for(int i=0;i<n;i++){
        if(a[i]!=ans){
            cout<<i+1<<"\n";
        }
    }
    
    cout<<"\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    while(t--){
        solve();
    }
    return 0;
}