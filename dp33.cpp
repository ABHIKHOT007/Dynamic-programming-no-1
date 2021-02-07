#include <bits/stdc++.h>
using namespace std;

//longest common subsequence of three strings.
//o(n^3)
/*
int lcsofthree(string X, string Y, string Z, int m, int n, int o)
{
    int dp[m + 1][n + 1][o + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= o; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else if (X[i - 1] == Y[j - 1] == Z[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }
    return dp[m][n][o];
}

int main()
{
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";

    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout << "length of longest common subsequence is:" << lcsofthree(X, Y, Z, m, n, o) << "\n";
    return 0;
}
*/

string X = "AGGT12";
string Y = "12TXAYB";
string Z = "12XBA";

int dp[100][100][100];

int lcsofthree(int i, int j, int k)
{
    if (i == -1 || j == -1 || k == -1)
    {
        return 0;
    }
    if (dp[i][j][k] = -1)
    {
        return dp[i][j][k];
    }
    if (X[i] == Y[j] && Y[j] == Z[k])
    {
        return dp[i][j][k] = 1 + lcsofthree(i - 1, j - 1, k - 1);
    }
    else
    {
        return dp[i][j][k] = max(max(lcsofthree(i - 1, j, k), lcsofthree(i, j - 1, k)), lcsofthree(i, j, k - 1));
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout << "Length of longest common sequence is:" << lcsofthree(m - 1, n - 1, o - 1);
    return 0;
}