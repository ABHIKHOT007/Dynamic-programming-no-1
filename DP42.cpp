#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

//Shortest Uncommon Subsequence.
//subsequence present in first sstring shoud't be in second string.
//No of possible subsequence of the string of length n is 2^n.
//Each character has two choices either it can come to the sequence or not so..
//recursive apporach.
/*

int shortestSequence(char *S, char *T, int m, int n)
{
    if (m == 0)
    {
        return MAX;
    }

    if (n <= 0)
    {
        return 1;
    }
    int k;
    for (k = 0; k < n; k++)
    {
        if (T[k] == S[0])
        {
            break;
        }
    }
    if (k == n)
    {
        return 1;
    }

    return min(shortestSequence(S + 1, T, m - 1, n), 1 + shortestSequence(S + 1, T + k + 1, m - 1, n - k - 1));
}

int main()
{
    char S[] = "babab";
    char T[] = "babba";
    int m = strlen(S);
    int n = strlen(T);
    int ans = shortestSequence(S, T, m, n);

    if (ans > MAX)
    {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}*/
//o((mn)^2) time.
//o(mn) space.

int ShortestSequence(char *S, char *T)
{
    int m = strlen(S);
    int n = strlen(T);

    int dp[m + 1][n + 1];

    //T string is empty.

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    //S string is empty.

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = MAX;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = S[i - 1];
            int k;

            for (k = j - 1; k >= 0; k--)
            {
                //if character is present break.

                if (T[k] == ch)
                {
                    break;
                }
            }
            if (k == -1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k]);
            }
        }
    }

    int ans = dp[m][n];
    if (ans >= MAX)
    {
        ans = -1;
    }
    return ans;
}

int main()
{
    char S[] = "babab";
    char T[] = "babba";

    int m = strlen(S);
    int n = strlen(T);

    cout << "lenght of the shortest subsequence is:" << ShortestSequence(S, T);
    return 0;
}