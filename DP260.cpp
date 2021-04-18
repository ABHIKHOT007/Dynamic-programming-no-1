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


/*void solve()
{
    int n;
    cin>>n;
    vector<p> v(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        v[i].first=a;
        v[i].second=b;
    }

    int ans=0;
    rep(x,n){
      rep(y,n){
          if((x!=y) && (v[x].first==v[y].second)){
              ans++;
          }
      }
    }

    cout<<ans<<"\n";
}*/

void solve()
{
    int n;
    cin >> n;

    int ans(0);
    vector<int> h(n), g(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i] >> g[i];
        for (int j = 0; j < i; ++j)
        {
            if (h[i] == g[j])
            {
                ans += 1;
            }
            if (g[i] == h[j])
            {
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}