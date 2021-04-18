#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod=1e+7;
int max(int a, int b) {return (a>b)?a:b;}
int min(int a, int b) {return (a<b)?a:b;}

void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    rep(i,n){
        string s;
        cin>>s;
        if(s=="Tetrahedron"){
          ans+=4;
        }
        else if(s=="Cube"){
            ans+=6;
        }
        else if(s=="Octahedron"){
            ans+=8;
        }
        else if(s=="Dodecahedron"){
            ans+=12;
        }
        else if(s=="Icosahedron"){
            ans+=20;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}