#include <bits/stdc++.h>
using namespace std;

//longest common subsequence.
//0(n^2)
/*
int lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();

    int l[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                l[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                l[i][j] = l[i - 1][j - 1] + 1;
            }
            else
            {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }
    return l[m][n];
}

int main()
{
    string X = "ABCDGH";
    string Y = "AEDFHR";

    cout << "length of the subsequence is:" << lcs(X, Y) << "\n";
    return 0;
}*/

//space optimization
//o(n) space complexity.
//o(m*n) time complexity.

int lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();

    int dp[2][n + 1];

    bool flag;

    for (int i = 0; i <= m; i++)
    {
        flag = i & 1;
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[flag][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[flag][j] = dp[1 - flag][j - 1] + 1;
            }
            else
            {
                dp[flag][j] = max(dp[1 - flag][j], dp[flag][j - 1]);
            }
        }
    }

    return dp[flag][n];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTYAB";

    cout << "length of longest common sequence is:" << lcs(X, Y);
    return 0;
}