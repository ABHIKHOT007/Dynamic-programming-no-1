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

bool solve()
{
    int n;
    cin>>n;
    char s[n];
    rep(i,n){
        cin>>s[i];
    }
    set<char> hashset;
    rep(i,n){
        if(('a'<=s[i]<='z')||('A'<=s[i]<='Z'))
        hashset.insert(s[i]);
    }
    int ans=hashset.size();
    return (ans==26)? true:false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve()?cout<<"YES":cout<<"NO";
    return 0;
}