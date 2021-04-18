#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(auto &it:a) cin>>it;

    map<int,int> first,second;

    for(auto i:a){
        first[a[i]]++;
        second[a[i]]=i;
    }

    for(auto x:first){
        if(x.second==1){
            cout<<second[x.first]<<"\n";
        }
    }

    return 0;
}