#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define mt make_tuple
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define ll long long
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ppb pop_back
#define ppcll __builtin_popcountll
#define mp make_pair
#define pll pair<lli, lli>
#define repll (ll, n) for (ll i = 1; i < (ll)i < n; i++)
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e9 + 7;
const int inf = 1e18;

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

void solve()
{
    int n,x;
    cin>>n;
    vector<int> v[4];
    for(int i=0;i<n;i++){
        cin>>x;
        v[x].pb(i+1);
    }
    int t=min(v[1].size(),min(v[2].size(),v[3].size()));
    cout<<t<<"\n";
    for(int i=0;i<t;i++){
        cout<<v[1][i]<<" "<<v[2][i]<<" "<<v[3][i]<<"\n";
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
   solve();
    return 0;
}

//1 3 1 3 2 1 2
//1 2 3 4 5 6 7 

// 3 5 2
// 6 7 4

