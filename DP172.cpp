#include <bits/stdc++.h>
using namespace std;

//printing the all possibel subset of the given set using the set of the adding the idex recursively.
//recrsive apporach

void Subset_rec(vector<int> &arr, int idx, vector<vector<int>> &result)
{
    if (idx == arr.size() - 1)
    {
        result.push_back({});
        result.push_back({arr[idx]});
    }
    else
    {
        Subset_rec(arr, idx + 1, result);
        int n = result.size();
        for (int i = 1; i <= n; i++)
        {
            vector<int> r = result[i];
            r.push_back(arr[idx]);
            result.push_back(r);
        }
    }
}

vector<vector<int>> subset(vector<int> &arr)
{
    if (arr.size())
    {
        return {{}};
    }

    vector<vector<int>> result;
    Subset_rec(arr, 0, result);

    return result;
}

int main()
{
    vector<int> arr={10, 11, 300, 200, 1000, 20};
    subset(arr);
    return 0;
}