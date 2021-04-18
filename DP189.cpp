#include<bits/stdc++.h>
using namespace std;
//Dominois tialing 
/*
int main()
{
    int n,m;
    cin>>n>>m;

    cout<<n*m/2;
    return 0;
}*/


int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &it:a) cin>>it;
        int pos=n-1;

        while(pos>0&&a[pos-1]>=a[pos]) --pos;
        while(pos>0&&a[pos-1]<=a[pos]) --pos;

        cout<<pos<<"\n";
    }
    return 0;
}