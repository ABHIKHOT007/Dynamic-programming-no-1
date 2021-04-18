#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define lli long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lli, lli>
const int mod = 1e+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n + 2);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        if (sum == a[n] || sum == a[n + 1])
        {
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
            continue;
        }
        else
        {
            bool flag = false;
            int index = 0;
            sum += a[n];
            for (int i = 0; i < n; i++)
            {
                if (sum - a[i] == a[n + 1])
                {
                    flag = true;
                    index = i;
                    break;
                }
            }
            if (!flag)
            {
                cout << "-1\n";
                continue;
            }
            for (int i = 0; i < n + 1; i++)
            {
                if (i == index)
                    continue;
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}
