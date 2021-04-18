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
    int a[128];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}