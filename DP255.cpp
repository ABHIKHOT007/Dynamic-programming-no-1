#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<int> s;
    int x,y;
    cin>>x;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    cin>>y;
    for(int i=0;i<y;i++){
        int b;
        cin>>b;
        s.insert(b);
    }

    if(s.size()==n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}