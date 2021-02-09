#include <bits/stdc++.h>
using namespace std;

//Maximum length chain of pairs.
//o(n^2)
/*
class Pair
{
public:
    int a;
    int b;
};

int maxChainLength(Pair arr[], int n)
{
    int max = 0;
    int *dp = new int[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].a < arr[j].b && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max < dp[i])
        {
            max = dp[i];
        }
    }

    return max;
}

int main()
{
    Pair arr[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "maximum length of the chain is:" << maxChainLength(arr, n);
    return 0;
}*/

struct val
{
    int first;
    int second;
};

map<pair<int, int>, int> m;

int findmaxchainlen(struct val p[], int n, int prev, int pos)
{
    if (m.find({pos, prev}) != m.end())
    {
        return m[{pos, prev}];
    }

    if (pos >= n)
    {
        return 0;
    }
    if (p[pos].first <= prev)
    {
        return findmaxchainlen(p, n, prev, pos + 1);
    }
    else
    {
        int ans = max(findmaxchainlen(p, n, p[pos].second, 0) + 1, findmaxchainlen(p, n, prev, pos + 1));
        m[{pos, prev}] = ans;
        return ans;
    }
}

int maxChainLen(struct val p[], int n)
{
    m.clear();
    int ans = findmaxchainlen(p, n, 0, 0);
    return ans;
}

int main()
{
    int n = 5;
    val p[n];
    p[0].first = 5;
    p[0].second = 24;

    p[1].first = 39;
    p[1].second = 60;

    p[2].first = 15;
    p[2].second = 28;

    p[3].first = 27;
    p[3].second = 40;

    p[4].first = 50;
    p[4].second = 90;

    cout << maxChainLen(p, n) << "\n";
    return 0;
}
