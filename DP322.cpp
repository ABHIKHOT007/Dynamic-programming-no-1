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
#define   pb emplace_back
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

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

void solve()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    //(a,b)=(0,0)
    //(c,d)=(1,1)
    //(e,f)=(0,1)
    cout<<3<<"\n";
    cout<<e+c-a<<" "<<f+d-b<<"\n";
    cout<<e+a-c<<" "<<f+b-d<<"\n";
    cout<<a+c-e<<" "<<b+d-f<<"\n";
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

