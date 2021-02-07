#include <bits/stdc++.h>
using namespace std;

//o(2^n)

int max(int a, int b);
/*
int lcs(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs(X, Y, m - 1, n - 1);
    }
    else
    {
        return max(lcs(X, Y, m, n -1), lcs(X, Y, m - 1, n));
    }
}*/

int lcs(char *X, char *Y, int m, int n)
{
    int l[m + 1][n + 1];
    int i, j;

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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "length of longest common sequence is:" << lcs(X, Y, m, n);
    return 0;
}