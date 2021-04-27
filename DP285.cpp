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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());
    if(a.size()>3){
        cout<<"-1"<<"\n";
    }
    else{
        if(a.size()==1){
            cout<<0<<"\n";
        }
        else if(a.size()==2){
            if((a[1]-a[0])%2==0){
                cout<<(a[1]-a[0])/2<<"\n";
            }
            else{
                cout<<a[1]-a[0]<<"\n";
            }
        }
        else{
            if(a[1]-a[0]!=a[2]-a[1]){
                cout<<-1<<"\n";
            }
            else{
                cout<<a[1]-a[0]<<"\n";
            }
        }
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