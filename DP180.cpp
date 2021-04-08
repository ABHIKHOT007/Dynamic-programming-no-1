#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, v, t, number(0);
    cin >> n;
    while (n--)
    {
        cin >> p >> v >> t;
        if (p + t + v >= 2)
        {
            number += 1;
        }
    }

    cout << number << "\n";
    return 0;
}