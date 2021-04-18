#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define lld long long double

#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define pll pair<lli, lli>
const int N = 200005;
const int mod = 1000000007;
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        dp[i] = 2;
    }
    dp[9] = 3;
    for (int i = 10; i < N; i++)
    {
        dp[i] = (dp[i - 9] + dp[i - 10]) % mod;
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while (n > 0)
        {
            int x = n % 10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n /= 10;
        }

        cout << ans << "\n";
    }

    return 0;
}