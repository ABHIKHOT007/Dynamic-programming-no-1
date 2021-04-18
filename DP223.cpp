#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lift[100000];
ll cost[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, str;
    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        cin >> lift[i];
    }
    ll A;
    cin >> A;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    priority_queue<ll> boost;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        boost.push(-cost[i]);
        while (str < lift[i])
        {
            if (boost.empty())
            {
                cout << -1 << "\n";
                return 0;
            }
            ans -= boost.top();
            str += A;
            boost.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}