#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>

int max(int a, int b) {return (a>b)?a:b;}
int min(int a, int b) {return (a<b)?a:b;}

void solve()
{
    int n;
    cin>>n;
    int maxele=0;
    int minele=1000;
    int maxpos=0;
    int minpos=0;
    
    rep(i,n){
        int x;
        cin>>x;
        if(x>maxele){
            maxpos=i;
            maxele=x;
        }
        if(x<=minele){
            minpos=i;
            minele=x;
        }
    }

    if(maxpos>minpos){
        cout<<(maxpos-1)+(n-minpos)-1<<"\n";
    }
    else{
        cout<<(maxpos-1)+(n-minpos)<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}