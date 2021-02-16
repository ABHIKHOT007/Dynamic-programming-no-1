#include <bits/stdc++.h>
using namespace std;

//space optimization for substring problem.
//(n*m)
//space complexity o(n)

int countsubstring(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int len[2][n];
    int currrow = 0;
    int result = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                len[currrow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                len[currrow][j] = len[1 - currrow][j - 1] + 1;
                result = max(result, len[currrow][j]);
            }
            else
            {
                len[currrow][j] = 0;
            }
        }
        currrow = 1 - currrow;
    }
    return result;
}

int main()
{
    string X = "GeeksforGeeks";
    string Y = "GeeksQuiz";
    cout << countsubstring(X, Y);
    return 0;
}