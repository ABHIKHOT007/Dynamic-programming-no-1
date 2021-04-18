#include<bits/stdc++.h>
using namespace std;

const int mod=100000007;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    unordered_map<int,char> hashmap;
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            hashmap[s[i]]=i;
        }
    }

    for(auto x:hashmap){
        cout<<x.first<<" "<<x.second<<"\n";
    }

    return 0;
}
