#include <bits/stdc++.h>
using namespace std;
//printing the all possible subsequence of the given string.
//recursive solution.
/*
void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << "\n";
        return;
    }

    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}

int main()
{
    string output = "";
    string input = "abcd";

    printSubsequence(input, output);
    return 0;
}
*/
//O(N^3)
/*
unordered_set<string> hashset;

void printSubsequence(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            hashset.insert(sub_str);
            for (int k = 1; k < sub_str.length(); k++)
            {
                string sub = sub_str;
                sub.erase(sub.begin() + k);
                printSubsequence(sub);
            }
        }
    }
}

int main()
{
    string str = "aabc";
    printSubsequence(str);
    for (auto i : hashset)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

*/

//another recursive solution.
//expoential time complexity.

void printSubsequenceUtil(string str, int n, int index = -1, string curr = "")
{
    if (index == n)
    {
        return;
    }

    if (!curr.empty())
    {
        cout << curr << "\n";
    }

    for (int i = index + 1; i < n; i++)
    {
        curr += str[i];
        printSubsequenceUtil(str, n, i, curr);
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

void printSubsequence(string str)
{
    printSubsequenceUtil(str, str.size());
}

int main()
{
    string str = "cab";
    printSubsequence(str);
    return 0;
}