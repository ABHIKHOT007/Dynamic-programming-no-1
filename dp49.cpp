#include <bits/stdc++.h>
using namespace std;
#define N 4
//minimum path in triangle.

int minPath(vector<vector<int>> &A)
{
    int memo[A.size()];
    int n = A.size() - 1;

    for (int i = 0; i < A[n].size(); i++)
    {
        memo[i] = A[n][i];
    }

    for (int i = A.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            memo[j] = A[i][j] + min(memo[j], memo[j + 1]);
        }
    }
    return memo[0];
}

int main()
{
    vector<vector<int>> A{{2}, {3, 9}, {1, 6, 7}};
    cout << minPath(A);
    return 0;
}