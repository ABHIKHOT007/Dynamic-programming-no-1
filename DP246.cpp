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

void solve()
{
    int n;
    cin >> n;
    vector<p> a(n);
    int pi, qi;
    for (int i = 0; i < n; i++)
    {
        cin >> pi >> qi;
        a[i] = {pi, qi};
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i].first + 2) <= a[i].second)
        {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}