#include <bits/stdc++.h>
using namespace std;

//Longest Palidromic substring with o(n) space.
//o(n*n)
//o(n) space complexity.

int lps(string str)
{
    int n = str.length();
    //for storing the maximum length of the palidromic substring.

    int dp[n];

    for (int i = n - 1; i >= 0; i--)
    {
        int back_up = 0;
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                //if string has only one latter.
                dp[j] = 1;
            }
            else if (str[i] == str[j])
            {
                //if first and lst character is same.
                int temp = dp[j];
                dp[j] = back_up + 2;
                back_up = temp;
            }
            else
            {
                //if first and last character are not same then we took maximum of the last maximum and this current max.
                back_up = dp[j];
                dp[j] = max(dp[j - 1], dp[j]);
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    string str = "GEEKFORGEEKS";
    cout << "Maximum lenght of the palidrome is:" << lps(str) << "\n";
    return 0;
}