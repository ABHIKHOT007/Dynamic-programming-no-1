#include <bits/stdc++.h>
using namespace std;

//maximum weight value ratio of avarage sum equals to the given k.
//recursive solution exits only.

int maxWeightUtil(int wt[], int val[], map<pair<int, int>, int> &mp, int last, int diff, int k)
{
    if (last == -1)
    {
        if (diff == 0)
        {
            return 0;
        }
        else
        {
            return INT_MIN;
        }
    }

    pair<int, int> temp = make_pair(last, diff);
    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    mp[temp] = max(maxWeightUtil(wt, val, mp, last - 1, diff, k), wt[last] + maxWeightUtil(wt, val, mp, last - 1, diff + wt[last] - val[last] * k, k));

    return mp[temp];
}

int maxWeight(int wt[], int val[], int k, int N)
{
    map<pair<int, int>, int> mp;
    return maxWeightUtil(wt, val, mp, N - 1, 0, k);
}

int main()
{
    int wt[] = {4, 8, 9};
    int val[] = {2, 4, 6};
    int k = 2;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << maxWeight(wt, val, k, n);
    return 0;
}