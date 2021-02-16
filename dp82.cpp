#include <bits/stdc++.h>
using namespace std;

//longest palidromic substring.
//o(n^3)

void printsubstring(string str, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        cout << str[i];
    }
}

int longestpalidromicstring(string str)
{
    int n = str.length();
    int maxLength = 1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
            {
                if (str[i + k] != str[j - k])
                {
                    flag = 0;
                }
            }
            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
    cout << "Longest palidrome substring is:" << endl;
    printsubstring(str, start, start + maxLength - 1);
    cout << "\n";
    return maxLength;
}
//o(n^2)

int longestpalidromestring(string str)
{
    int n = str.length();
    bool dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int maxLength = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;
                if (k > maxLength)
                {
                    str = i;
                    maxLength = k;
                }
            }
        }
    }
    cout << "Longest palidromic substring is:" << endl;
    printsubstring(str, start, start + maxLength - 1);
    return maxLength;
}
//o(n^2)

int longestpalidromestring(char *str)
{
    int maxLength = 1;
    int start = 0;
    int len = strlen(str);
    int low, high;
    for (int i = 1; i < len; i++)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high <= len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                maxLength = high - low + 1;
            }
            --low;
            high++;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    cout << "Longest palidrome substring is:"
         << "\n";
    printsubstring(str, start, start + maxLength - 1);
    cout << "\n";
    return maxLength;
}

int main()
{
    string str = "forgeeksskeegfor";
    cout << longestpalidromicstring(str);
    return 0;
}