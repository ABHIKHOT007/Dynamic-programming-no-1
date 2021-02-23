#include <bits/stdc++.h>
using namespace std;

int dictonaryConatains(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "iceream", "and", "go", "i", "like", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
    {
        if (dictionary[i].compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

bool WordConatins(string str)
{
    int n = str.size();
    if (n == 0)
    {
        return true;
    }

    vector<int> dp(n + 1, 0);

    vector<int> matched_index;
    matched_index.push_back(-1);

    for (int i = 0; i < n; i++)
    {
        int msize = matched_index.size();

        int f = 0;

        for (int j = msize - 1; j >= 0; j--)
        {
            string sb = str.substr(matched_index[j] + 1, i - matched_index[j]);
            if (dictonaryConatains(sb))
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
        {
            dp[i] = 1;
            matched_index.push_back(i);
        }
    }
    return dp[n - 1];
}

int main()
{
    WordConatins("ilikesamsung") ? cout << "YES" : cout << "NO";
    return 0;
}