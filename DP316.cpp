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

/*
void solve()
{
    vector<int> v(5);
    int sum=0;
    for(int i=0;i<5;i++){
        cin>>v[i];
        sum+=v[i];
    }
    
    int best=sum;
    
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(v[i]==v[j]){
                best=min(best,sum-2*v[i]);
            }
        }
    }

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
               if(v[i]==v[j]&&v[i]==v[k]){
                   best=min(best,sum-3*v[i]);
               }
            }
        }
    }

    cout<<best<<"\n";
}
*/

void solve()
{
    vector<int> v(5);
    int sum=0;
    for(int i=0;i<5;i++){
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    int best=0;
    for(int i=0;i<5;i++){
        if(i+1<5&&v[i]==v[i+1]){
            best=max(best,2*v[i]);
        }
        if(i+2<5&&v[i]==v[i+2]){
            best=max(best,3*v[i]);
        }
    }
    cout<<sum-best<<"\n";
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

