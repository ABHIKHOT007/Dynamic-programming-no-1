#include <bits/stdc++.h>
using namespace std;

//word segementation problem.
//o(n^2)
//memoization apporach.

int dictionaryConatins(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "iceream", "and", "go", "i", "like", "ice", "cream"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < size; i++)
    {
        if (dictionary[i].compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

bool WordConstains(string str)
{
    int n = str.size();
    if (n == 0)
    {
        return true;
    }

    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == false && dictionaryConatins(str.substr(0, i)))
        {
            dp[i] = true;
        }
        if (dp[i] == true)
        {
            if (i == n)
            {
                return true;
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (dp[j] == false && dictionaryConatins(str.substr(i, j - 1)))
                {
                    dp[j] = true;
                }
                if (j == n && dp[j] == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    WordConstains("ilikesamsung")?cout<<"YES":cout<<"NO";
    return 0;
}