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
#define     rep(a,b) for (int i = a; (int)i <=b; i++)
#define     p pair<int, int>

const int mod=1e9+7;
const int inf=1e18;

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

void solve()
{
    int n;
    cin>>n;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2!=i%2){
            if(i%2==0){
                a++;
            }
            else{
                b++;
            }
        }
    }
    (a!=b)?cout<<-1<<"\n":cout<<a<<"\n";
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
    int t=1;
    cin>>t;
   while(t--){
       solve();
   }
    return 0;
}


