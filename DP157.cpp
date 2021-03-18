#include <bits/stdc++.h>
using namespace std;

//minimum jumps required to reach end of the array.
//at every position in the array given number that is minimum
//jumps you can take from that current position you can't go out of array length.
//recursive apporach
//O(N^N)

/*

int minJumps(int arr[], int n)
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
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}*/

//O(N^2)

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int minJumps(int arr[], int n)
{
    if (n == 0 || arr[0] == 0)
    {
        return INT_MAX;
    }

    int *jumps = new int[n];
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

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n);
    return 0;
}