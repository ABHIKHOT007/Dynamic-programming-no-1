#include <bits/stdc++.h>
using namespace std;

//printing the word break problems segments words.
//o(n^n)

int dictionaryConatins(string &word)
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

void WordBreakUtil(string str, int n, string result)
{
    for (int i = 1; i <= n; i++)
    {
        string prefix = str.substr(0, i);
        if (dictionaryConatins(prefix))
        {
            if (i == n)
            {
                result += prefix;
                cout << result << "\n";
                return;
            }
            WordBreakUtil(str.substr(i, n - i), n - i, result + prefix + "");
        }
    }
}

void WordBreak(string str)
{
    WordBreakUtil(str, str.size(), "");
}

int main()
{
    WordBreak("ilikeiceramsamsungdomango");
    return 0;
}