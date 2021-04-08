#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if (n % 2 == 0)
    {
        if (n <= 2)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n";
        }
    }
    else
    {
        cout << "NO"
             << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}