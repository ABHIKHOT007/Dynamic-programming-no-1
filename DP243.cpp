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

bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> tt, mm;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            tt.pb(i);
        }
        else
        {
            mm.pb(i);
        }
    }
    if (tt.size() != 2 * mm.size())
    {
        return false;
    }
    for (int i = 0; i < mm.size(); i++)
    {
        if (mm[i] < tt[i] || mm[i] > tt[i + mm.size()])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}