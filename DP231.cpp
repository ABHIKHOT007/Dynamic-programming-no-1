#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int ans=0;
    while(b>=a){
        ans+=1;
        a=a*3;
        b=b*2;
    }
    cout<<ans<<"\n";
    return 0;
}