#include <bits/stdc++.h>
using namespace std;

//longest string chain problem.
//string chain when you can concatenate at most one character to the
//new string to be able to get new string like below
//a->ab->bda->bdca.
//O(N^2)

int longestStringChain(vector<string> &v, int n)
{
    unordered_map<string, int> hash;
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int best = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            string str = v[i].substr(0, j) + v[i].substr(j + 1);
            best = max(best, hash[str] + 1);
        }
        hash[v[i]] = best;
        ret = max(ret, hash[v[i]]);
    }
    return ret;
}

int main()
{
    vector<string> v = {"a", "b", "ba", "bca", "bda", "bdca"};
    int n = v.size();
    cout << longestStringChain(v, n);
    return 0;
}