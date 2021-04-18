#include <bits/stdc++.h>
using namespace std;
#define lii long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define rep(i, n) for (int i = (int)n; i>=0; i--)
#define p pair<int, int>
const int mod = 1e+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    bool flag = true;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[n - i - 1] == t[i])
        {
            continue;
        }
        else
        {
            flag = false;
            cout << "NO"
                 << "\n";
            break;
        }
    }

    if (flag == true)
    {
        cout << "YES"
             << "\n";
    }

    return 0;
}