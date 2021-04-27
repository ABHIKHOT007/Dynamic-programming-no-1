#include <bits/stdc++.h>
using namespace std;

#define   ff first
#define   ss second
#define   int long long
#define   mt make_tuple
#define   pqb priority_queue<int>
#define   pqs priority_queue<int, vi, greater<int>>
#define   setbits(x) __builtin_popcountll(x)
#define   ll long long
#define   pb push_back
#define   pf push_front
#define   ppf pop_front
#define   ppb pop_back
#define   ppcll __builtin_popcountll
#define   mp make_pair
#define   pll pair<lli, lli>
#define   repll (ll, n) for (ll i = 1; i < (ll)i < n; i++)
#define   rep(i, n) for (int i = 1; (int)i <= n; i++)
#define   p pair<int, int>

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn =2e5+5;

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

void solve()
{
    int n;
    cin>>n;
    vector<int> v(maxn);
    vector<int> even,odd;
    for(int i=1;i<=2*n;i++){
        cin>>v[i];
        if(v[i]%2==0){
            even.pb(i);
        }
        else{
            odd.pb(i);
        }
    }
    vector<p> ans;
    for(int i=0;i+1<odd.size();i+=2){
        ans.pb({odd[i],odd[i+1]});
    }
    for(int i=0;i+1<even.size();i+=2){
        ans.pb({even[i],even[i+1]});
    }

    for(int i=0;i<n-1;i++){
        cout<<ans[i].ff<<" "<<ans[i].ss<<"\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

