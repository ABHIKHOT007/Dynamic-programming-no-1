#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define ver(i, n) for (int i = n - 1; (int)i >= 0; i--)
#define p pair<int, int>

void solve()
{
    int n;
    cin >> n;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }

    cout << float(sum / n) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}