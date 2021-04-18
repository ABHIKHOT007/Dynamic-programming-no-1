#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 0; i < int(n); i++)
const int mod = 1e+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> f(n);
        vector<pair<int, int>> p;
        rep(i, n)
        {
            cin >> f[i];
            rep(j, n)
            {
                if (f[i][j] == '*')
                {
                    p.pb({i, j});
                }
            }
        }

        p.pb(p[0]);
        p.pb(p[1]);

        //same row
        if (p[0].first == p[1].first + 1)
        {
            p[2].first = (p[2].first + 1) % n;
            p[3].first = (p[3].first + 1) % n;
        }
        //same column
        else if (p[0].second == p[1].second)
        {
            p[2].second = (p[2].second + 1) % n;
            p[3].second = (p[3].second + 1) % n;
        }
        //otherwise.
        else
        {
            swap(p[2].first, p[3].first);
            f[p[2].first][p[2].second] = '*';
            f[p[3].first][p[3].second] = '*';
        }
        //final points of the rectangle

        cout << p[0].first << " " << p[0].second << "\n";
        cout << p[1].first << " " << p[1].second << "\n";
        cout << p[2].first << " " << p[2].second << "\n";
        cout << p[3].first << " " << p[3].second << "\n";

        rep(i, n) cout << f[i] << "\n";
    }
}
