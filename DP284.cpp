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
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,p> m1;
    unordered_map<int,int> m2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            if(m2.find(sum)!=m2.end()){
                int a=m1[sum].first;
                int b=m1[sum].second;
                if(a!=i and b!=i and a!=j and b!=j){
                    cout<<"YES"<<"\n";
                    cout<<i+1<<" "<<j+1<<" "<<a+1<<" "<<b+1<<"\n";
                }
                else{
                    m1[sum]={i,j};
                    m2[sum]=1;
                }
            }
        }
    }
    cout<<"NO"<<"\n";
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