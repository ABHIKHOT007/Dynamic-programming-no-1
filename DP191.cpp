#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a;
    cin>>n>>m>>a;

    int i=n/a;
    int j=m/a;

    if(a*i!=n){
        i++;
    }
    if(j*a!=m){
        j++;
    }

    cout<<i*j<<"\n";
    return 0;
}