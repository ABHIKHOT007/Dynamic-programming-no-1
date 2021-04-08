#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<n;i++){
        for(int li=i+1;li<n;li++){
            long long lol =v[i]+v[li];
            if(m.find(lol)!=m.end()){
                int a=m[lol].first;
                int b=m[lol].second;
                if(a==i||a==li||b==i||b==li)continue;
                cout<<"YES"<<"\n";
                cout<<a+1<<" "<<b+1<<" "<<i+1<<" "<<li+1<<"\n";
                return;
            }
            m[lol]={i,li};
        }
    }
    cout<<"NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}