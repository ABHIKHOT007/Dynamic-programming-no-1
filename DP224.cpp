#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        int n,c;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b(n-1);
        for(int i=0;i<(n-1);i++){
            cin>>b[i];
        }
        b.push_back(0);
        ll ans=INT_MAX;
        ll cur=0;
        ll bal=0;
        for(int i=0;i<n;i++){
            ans=min(ans,cur+max(0ll,c-bal+a[i]-1)/a[i]);
            ll newday=max(0ll,b[i]-bal+a[i]-1)/a[i];
            cur+=newday+1;
            bal+=a[i]*newday-b[i];
        }
        cout<<ans<<"\n";
    }
}