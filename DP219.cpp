#include <bits/stdc++.h>
using namespace std;
#define lii long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0; (int)i < n; i++)
#define p pair<int, int>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    //for chaning lowercase to uppercase substract 32
    //for chaning uppercase to lowercase add 32
    if(s[0]>='a'&&s[0]<='z'){
        s[0]=s[0]-32;
    }
    cout<<s<<"\n";
    return 0;
}