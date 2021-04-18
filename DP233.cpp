#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int capacity=0;
    int current=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        current-=a;
        current+=b;
        capacity=max(capacity,current);
    }
    cout<<capacity;
    return 0;
}