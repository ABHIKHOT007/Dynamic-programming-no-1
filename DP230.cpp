#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k,n,w;
    cin>>k>>n>>w;
    int totalcost=0;
    for(int i=1;i<=w;i++){
        totalcost+=i*k;
    } 
    if(n>=totalcost){
        cout<<"0"<<"\n";
    }
    else{
        cout<<totalcost-n<<"\n";
    }
    return 0;
}