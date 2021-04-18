#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>


void solve()
{
   vector<ll> a(4);
   for(int i=0;i<4;i++){
       cin>>a[i];
   }

   ll cnt=0;
   for(ll i=0;i<4;i++){
       if(a[i]!=a[i+1]){
           cnt++;
       }
   }
   cout<<4-cnt<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}