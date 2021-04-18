#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli,lli> 
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        vector<int> a(3);
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        if(a[1]!=a[2]){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n"<<a[0]<<" "<<a[0]<<" "<<a[2]<<"\n";
        }
    }

    return 0;
}