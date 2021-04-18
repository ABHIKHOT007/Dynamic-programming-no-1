#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int A=count(s.begin(),s.end(),'A');
    int D=count(s.begin(),s.end(),'D');
    if(A>D){
        cout<<"Anton"<<"\n";
    }
    if(D>A){
        cout<<"Danik"<<"\n";
    }
    if(A==D){
        cout<<"Friendship"<<"\n";
    }
    
    return 0;
}