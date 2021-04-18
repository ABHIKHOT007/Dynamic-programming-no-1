#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define repll (ll, n) for (ll i = 1; i < (ll)i < n; i++)
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }


void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    ll maxele=0;
    for(ll &x:a){
        cin>>x;
        sum+=x;
        maxele=max(maxele,x);
    }
    if((sum%2==0)&&(maxele<=sum/2)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
