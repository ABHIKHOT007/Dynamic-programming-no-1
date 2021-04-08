#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;
int ans = 0;

void solve()
{
    cin >> n >> k;
    cin >> s;
    int l = 0;
    int h = n - 1;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i + 1])
        {
            ans++;
        }
    }
    if (ans == k)
    {
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, i = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
}