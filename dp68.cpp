#include <bits/stdc++.h>
using namespace std;

//minimum jumps to reach end.
//o(n*n)
/*
int minjumps(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }

    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minjumps(arr, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}*/

//o(n^2)
/*
int minjumps(int arr[], int n)
{
    int *jumps = new int[n];
    int i, j;
    if (n == 0 || arr[0] == 0)
    {
        return INT_MAX;
    }
    jumps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
*/

int minjumps(int arr[], int n)
{
    int *jumps = new int[n];
    int min;

    jumps[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            jumps[i] = INT_MAX;
        }
        else if (arr[i] >= n - i - 1)
        {
            jumps[i] = 1;
        }
        else
        {
            min = INT_MAX;
            for (int j = i + 1; j < n && j <= arr[i] + i; j++)
            {
                if (min > jumps[j])
                {
                    min = jumps[j];
                }
                if (min != INT_MAX)
                {
                    jumps[i] = min + 1;
                }
                else
                {
                    jumps[i] = min;
                }
            }
        }
    }
    return jumps[0];
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "minimum number of jumps to rech the end is:" << minjumps(arr, n);
    return 0;
}