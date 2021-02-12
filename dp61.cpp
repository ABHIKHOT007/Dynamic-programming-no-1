#include <bits/stdc++.h>
using namespace std;

//Maximum diffenence of the zeroes and onces in the binary string.

int maxDiff(string s, int n)
{
    int curr_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += (s[i] == '0' ? 1 : -1);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        max_sum = max(curr_sum, max_sum);
    }
    return (max_sum == 0 ? 0 : max_sum);
}

int main()
{
    string s = "11000010001";
    int n = s.length();
    cout << maxDiff(s, n);
    return 0;
}