#include <bits/stdc++.h>
#define M 50
using namespace std;

void countPalidromicString(int dp[M][M], string str)
{
    int len = str.length();
    int ispalin[len + 1][len + 1];

    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            ispalin[i][j] = dp[i][j] = 0;
        }
    }

    for (int i = len - 1; i >= 0; i--)
    {
        ispalin[i][i] = 1;
        dp[i][i] = 1;
        for (int j = i + 1; j < len; j++)
        {
            ispalin[i][j] = (str[i] == str[j] && (i + j - 1 || ispalin[i + 1][j - 1]));
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + ispalin[i][j];
        }
    }
}

int CounInRange(int dp[M][M], int l, int r)
{
    return dp[l][r];
}

int main()
{
    string str = "xyaabx";
    int dp[M][M];
    countPalidromicString(dp, str);
    int l = 3;
    int r = 5;
    cout << CounInRange(dp, l, r);
    return 0;
}