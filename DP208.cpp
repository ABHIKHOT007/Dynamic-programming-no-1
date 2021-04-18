#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;
int cnt=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int min1=*min_element(a.begin(),a.end());
        for(int x:a){
            if(min1==x) cnt++;
            if((min1&x)!=min1){
                cout<<"0"<<"\n";
                break;
            }
        }

        int fact=1;
        for(int i=1;i<=n-2;i++) fact=(1LL*fact*i)%MOD;
        int ans=(1LL*cnt*(cnt-1))%MOD;
        ans=(1LL*ans*fact)%MOD;
        cout<<ans<<"\n";
    }

    return 0;   
}