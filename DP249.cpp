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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
        {
            continue;
        }
        else
        {
            flag = false;
        }
    }

    return (flag) ? true : false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "EASY"
                   << "\n"
            : cout << "HARD"
                   << "\n";
    return 0;
}