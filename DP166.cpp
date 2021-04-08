#include <bits/stdc++.h>
using namespace std;

//k goodness sore of the string
//O(logn)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1, kt;
    cin >> kt;
    while (t <= kt)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int good = 0, bad = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - 1 - i])
                bad++;
            else
                good++;
        }
        int ans = 0;
        if (good == k)
            ans = 0;
        else
        {
            if (good < k)
            {
                ans = k - good;
            }
            else
                ans = good - k;
        }
        cout << "Case #" << t << ": " << ans << "\n";
        t++;
    }
}