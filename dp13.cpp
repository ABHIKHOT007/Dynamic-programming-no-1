#include <bits/stdc++.h>
using namespace std;

//Word break problem.
//standard recursive apporach.
//Exponential time complexity.

int dictionaryContains(string word)
{
    string dictonary[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "iceream", "and", "go", "i", "like", "ice", "cream"};

    int size = sizeof(dictonary) / sizeof(dictonary[0]);

    for (int i = 0; i < size; i++)
    {
        if (dictonary[i].compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

bool isContain(string str)
{
    int n = str.size();

    if (n == 0)
    {
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dictionaryContains(str.substr(0, i)) && isContain(str.substr(i, n - i)))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    isContain("ilikesamsung") ? cout << "YES" : cout << "NO";
    return 0;
}