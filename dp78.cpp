#include <bits/stdc++.h>
using namespace std;

//longest common substring.
//o(n*m)
/*
int lenghtofsubstring(char *X, char *Y, int m, int n)
{
    int dp[m + 1][n + 1];
    int result = 0;
    for (int i = 0; i <= n; i++)
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
                result = max(result, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);
    cout << lenghtofsubstring(X, Y, m, n);
    return 0;
}
*/

string X, Y;

int substring(int i, int j, int count)
{
    if (i == 0 || j == 0)
    {
        return count;
    }
    if (X[i - 1] == Y[j - 1])
    {
        count = substring(i - 1, j - 1, count +  1);
    }
    count = max(count, max(substring(i, j - 1, 0), substring(i - 1, j, 0)));
    return count;
}

int main()
{
    int n, m;
    X = "abcdxyz";
    Y = "xyzabcd";
    n = X.size();
    m = Y.size();
    cout << substring(n, m, 0);
    return 0;
}