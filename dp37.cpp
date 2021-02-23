#include <bits/stdc++.h>
using namespace std;

void lcs(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int dp[2][n + 1];
    bool flag = 0;
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
                dp[flag][j] = dp[flag - 1][j - 1] + 1;
            }
            else
            {
                dp[flag][j] = max(dp[1 - flag][j], dp[flag][j - 1]);
            }
        }
    }

    int len = dp[2][n];
    char lcs[len + 1];
    lcs[len] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[len - 1] = X[i - 1];
            i--;
            j--;
            len--;
        }
        else if (dp[flag - 1][j] > dp[flag][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << lcs;
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTAYAB";
    lcs(X, Y);
    return 0;
}