#include<bits/stdc++.h>
using namespace std;
const int max_a=200005;
const int mod=1e+7;
int dp[max_a];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<9;i++) dp[i]=2;
    dp[9]=3;

    for(int i=10;i<max_a;i++){
        dp[i]=(dp[i-9]+dp[i-10])%mod;
    }

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans=0;
        while(n>0){
            int x=n%10;
            ans+=((m+x<10)?1:dp[m+x-10]);
            ans%=mod;
            n/10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}