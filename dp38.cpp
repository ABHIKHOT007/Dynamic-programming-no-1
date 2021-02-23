#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int lcs(char *X, char *Y, int m, int n)
{

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int ShortestSupersequence(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    int len = lcs(X, Y, m, n);

    return (m + n - len);
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout << ShortestSupersequence(X, Y);
    return 0;
}