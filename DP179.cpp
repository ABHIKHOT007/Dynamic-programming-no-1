#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define P pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define db(x) cout << #x << " : " << x << endl
struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
void solve()
{
  ll n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  unordered_map<ll, pair<ll, ll>> m2;
  unordered_map<ll, ll> m3;
  for (int i = 0; i < min(n, (ll)4000); i++)
  {
    for (int j = i + 1; j < min(n, (ll)4000); j++)
    {
      if (m3[arr[i] + arr[j]])
      {
        if (m2[arr[i] + arr[j]].F != i and m2[arr[i] + arr[j]].S != i and m2[arr[i] + arr[j]].F != j and m2[arr[i] + arr[j]].S != j)
        {
          cout << "YES"
               << "\n";
          cout << i + 1 << " " << j + 1 << " " << m2[arr[i] + arr[j]].first + 1 << " " << m2[arr[i] + arr[j]].second + 1 << endl;
          return;
        }
      }
      else
      {
        m2[arr[i] + arr[j]] = mp(i, j);
        m3[arr[i] + arr[j]] = 1;
      }
    }
  }
  cout << "NO"
       << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}