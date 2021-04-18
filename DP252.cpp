#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define p pair<int, int>
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
const int mod = 1e+7;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    for (size_t i = 0; i <= s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '0';
        }
        else
        {
            s1[i] = '1';
        }
    }
    cout << s1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}