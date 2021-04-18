#include <bits/stdc++.h>
using namespace std;
#define lii long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0; (int)i < n; i++)
#define p pair<int, int>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int x;
        cin >> x;
        int ans = find(a.begin(), a.end(), x) - a.begin();
        cout << ans + 1 << "\n";
        rotate(a.begin(), a.begin() + ans, a.begin() + ans + 1);
    }
    return 0;
}