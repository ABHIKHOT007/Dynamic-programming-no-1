#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pb push_back
#define mp make_pair
#define rep1(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(j, n) for (int j = 0; j < (int)n; j++)
#define pp pair<int, int>
#define ppl pair<lli, lli>
#define mod 1e+7

bool check(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int all_a = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'a')
            {
                all_a = false;
            }
        }

        if (all_a)
        {
            cout << "NO"
                 << "\n";
                 return;
        }

        if (check('a' + s))
        {
            cout << "YES"
                 << "\n"
                 << 'a' + s << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n"
                 << 'a' + s << "\n";
        }
    }
    return 0;
}