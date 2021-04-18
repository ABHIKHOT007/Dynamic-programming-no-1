#include <bits/stdc++.h>
using namespace std;
#define lii long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod = 1e+7;
const int N = 1e+6;

void solve()
{
    ll n, m, pos;
    cin >> n >> m >> pos;
    pos--;
    ll col = pos / n;
    ll row = pos % n;
    cout << row * m + col + 1 << "\n";
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
        solve();
    }
    return 0;
}