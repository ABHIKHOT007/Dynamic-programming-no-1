#include <bits/stdc++.h>
using namespace std;

#define      ff first
#define      ss second
#define      int long long
#define      mt make_tuple
#define      pqb priority_queue<int>
#define      pqs priority_queue<int, vi, greater<int>>
#define      setbits(x) __builtin_popcountll(x)
#define      ll long long
#define      pb push_back
#define      pf push_front
#define      ppf pop_front
#define      ppb pop_back
#define      ppcll __builtin_popcountll
#define      mp make_pair
#define      pll pair<lli, lli>
#define      repll (ll, n) for (ll i = 1; i < (ll)i < n; i++)
#define      rep(i, n) for (int i = 1; (int)i <= n; i++)
#define      p pair<int, int>

const int mod = 1e9 + 7;
const int inf = 1e18;

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    int n=s.length();
    int flag=0;
   for(int i=0;i<n;i++){
       if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1'&&s[i+3]=='1'&&s[i+4]=='1'&&s[i+5]=='1'&&s[i+6]=='1'){
           flag=7;
           break;
       }
       else if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0'&&s[i+3]=='0'&&s[i+4]=='0'&&s[i+5]=='0'&&s[i+6]=='0'){
           flag=7;
            break;
       }
   }

   if(flag==7){
       cout<<"YES"<<"\n";
   }
   else{
       cout<<"NO"<<"\n";
   }
    return 0;
}