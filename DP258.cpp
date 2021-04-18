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
    string s;
    getline(cin,s);
    set<char> feq;
    int i=0;
   while(s[i]){
       if(isalpha(s[i])){
           feq.insert(s[i]);
       }
       i++;
   }

    cout<<feq.size()<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}