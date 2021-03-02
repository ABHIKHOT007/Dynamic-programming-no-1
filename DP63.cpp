#include <bits/stdc++.h>
using namespace std;

//Longest increasing subsequence.
//o(n)

int signnum(int n);

int LongestAlternatingSubsequence(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int LastSign = 0;
    int length = 1;

    for (int i = 1; i < n; i++)
    {
        int sign = signnum(arr[i] - arr[i - 1]);
        if (sign != LastSign && sign != 0)
        {
            LastSign = sign;
            length++;
        }
    }
    return length;
}

int signnum(int n)
{
    if (n != 0)
    {
        return n > 0 ? 1 : -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LongestAlternatingSubsequence(arr, n);
    return 0;
}