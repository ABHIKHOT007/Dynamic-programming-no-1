#include <bits/stdc++.h>
using namespace std;
#define lii long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
        }
        vector<int> ans(n);
        for(int i=0;i<2*n;i++){
            if(find(ans.begin(),ans.end(),a[i])!=ans.end()){
                continue;
            }
            else{
                ans.pb(a[i]);
            }
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0){
                cout<<ans[i]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
