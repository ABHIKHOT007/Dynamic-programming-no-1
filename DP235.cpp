#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    int cnt = 0;
    while (n)
    {
        if (n % 10 == 4 || n % 10 == 7)
        {
            cnt++;
        }
        n /= 10;
    }

    if (cnt == 4 || cnt == 7)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
    return 0;
}