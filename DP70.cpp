#include <bits/stdc++.h>
#define N 100
int dp[N][N];
using namespace std;

//printing the longest common subsequence.
//recursive apporach


set<string> findLCS(string X, string Y, int m, int n)
{
    set<string> s;
    if (n == 0 || m == 0)
    {
        s.insert("");
        return s;
    }

    if (X[m - 1] == Y[n - 1])
    {
        set<string> tmp = findLCS(X, Y, m - 1, n - 1);
        for (string str : tmp)
        {
            s.insert(str + X[m - 1]);
        }
    }
    else
    {
        if (dp[m - 1][n] >= dp[m][n - 1])
        {
            set<string> tmp = findLCS(X, Y, m - 1, n);
            for (string str : tmp)
            {
                s.insert(str);
            }
        }

        if (dp[m][n - 1] >= dp[m - 1][n])
        {
            set<string> tmp = findLCS(X, Y, m, n - 1);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}

int LCS(string X, string Y, int m, int n)
{
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

int main()
{
    string X = "AGTGATG";
    string Y = "GTAGT";
    int m = X.length();
    int n = Y.length();
    cout << LCS(X, Y, m, n);
    cout << "\n";
    set<string> s = findLCS(X, Y, m, n);

    for (string str : s)
    {
        cout << str << endl;
    }

    return 0;
}