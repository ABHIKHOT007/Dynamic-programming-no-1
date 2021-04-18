#include<bits/stdc++.h>
using namespace std;

int ans[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        if(k>(n-1)/2){
            puts("-1"); continue;
        }
        int x=n;
        for(int i=1;i<=n;i++) ans[i]=0;
        for(int i=2;i<n;i+=2){
            if(x<n-k) break;
            ans[i]=x--;
        }
        x=1;
        for(int i=1;i<=n;i++){
            if(ans[i]) continue;
            ans[i]=x++;
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}