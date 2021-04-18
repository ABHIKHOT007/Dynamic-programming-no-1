#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>

void solve()
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    if (k == 1 || l == 1 || m == 1 || n == 1)
    {
        cout << d << "\n";
    }
    else
    {
        int cnt = d;
        for (int i = 1; i <= d; i++)
        {
            if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0))
            {
                cnt--;
            }
        }
        cout << cnt << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}