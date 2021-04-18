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
    int a, b, c, d;
    while (true)
    {
        n += 1;
        a = n / 1000;
        b = n / 100 % 10;
        c = n / 10 % 10;
        d = n % 10;
        if (a != b && a != c && a != d && b != c && b != c && b != d && c != d)
        {
            break;
        }
    }
    cout << n << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}