#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            v1.pb(a[i]);
        }
        else{
            v2.pb(a[i]);
        }
    }

    for(auto i:v2){
        cout<<i<<" ";
    }
    for(int i:v1){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}