#include <bits/stdc++.h>
using namespace std;

//sum of substring of string represeting the given number
//o(n)
//o(n)space

int todigit(char ch)
{
    return (ch - '0');
}
/*
int sumofsunstring(string str)
{
    int n = str.length();
    int sum[n];
    sum[0] = todigit(str[0]);
    int res = sum[0];
    for (int i = 1; i < n; i++)
    {
        int numi = todigit(str[i]);
        sum[i] = (i + 1) * numi + 10 * sum[i - 1];
        res += sum[i];
    }
    return res;
}*/

//o(1) space complexity

int sumofsubstring(string str)
{
    int n = str.length();
    int prev = todigit(str[0]);
    int res = prev;
    int current = 0;

    for (int i = 1; i < n; i++)
    {
        int num = todigit(str[i]);
        current = (i + 1) * num + 10 * prev;
        res += current;
        prev = current;
    }
    return res;
}

int main()
{
    string str = "1234";
    cout << sumofsubstring(str);
    return 0;
}