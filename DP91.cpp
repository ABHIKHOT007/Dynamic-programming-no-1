#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

//printing the 1 to n number with no consecutive 1 in binary represention.

void BinaryRep(int N, vector<int> ans)
{
    if (ans.size() <= N)
    {
        int res = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            res += pow((double)2, i) * ans[ans.size() - 1 - i];
        }
        m[res] = 1;
        int last_element = ans[ans.size() - 1];
        if (last_element == 1)
        {
            ans.push_back(0);
            BinaryRep(N, ans);
        }
        else
        {
            ans.push_back(1);
            BinaryRep(N, ans);
            ans.pop_back();
            ans.push_back(0);
            BinaryRep(N, ans);
        }
    }
}

int main()
{
    int N = 4;
    vector<int> ans;
    ans.push_back(1);
    BinaryRep(N, ans);
    for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " ";
    }
    return 0;
}