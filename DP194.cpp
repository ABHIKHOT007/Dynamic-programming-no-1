#include<bits/stdc++.h>
using namespace std;
#define all(n) (n).begin(),(n).end();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    vector<string> v(n);

    for(auto &it:v) cin>>it;

    int inc1=count(v.begin(),v.end(),"++X");
    int inc2=count(v.begin(),v.end(),"X++");
    int dec1=count(v.begin(),v.end(),"--X");
    int dec2=count(v.begin(),v.end(),"X--");

    cout<<(inc1+inc2)-(dec1+dec2)<<"\n";

    return 0;
}