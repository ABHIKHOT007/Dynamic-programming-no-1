#include <bits/stdc++.h>
using namespace std;

#define     ff first
#define     ss second
#define     int long long 
#define     mt make_tuple
#define     pqb priority_queue<int>
#define     pqs priority_queue<int,vi,greater<int> >
#define     setbits(x) __builtin_popcountll(x)
#define     ll long long
#define     pb push_back
#define     pf push_front
#define     ppf pop_front
#define     ppb pop_back
#define     ppcll __builtin_popcountll
#define     mp make_pair
#define     pll pair<lli, lli>
#define     repll (ll, n) for (ll i = 1; i < (ll)i < n; i++)
#define     rep(a,b) for (int i = a; (int)i <b; i++)
#define     p pair<int, int>
const int mod=1e9+7;
const int inf=1e18;

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

void solve()
{
   vector<int> a;
   int x1,x2,x3,x4;
   cin>>x1>>x2>>x3>>x4;
   a.pb(x1);
   a.pb(x2);
   a.pb(x3);
   a.pb(x4);
   sort(a.begin(),a.end());
   cout<<(a[3]-a[2])<<" "<<(a[3]-a[1])<<" "<<(a[3]-a[0])<<"\n";
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