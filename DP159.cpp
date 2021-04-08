#include <bits/stdc++.h>
using namespace std;

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int minJumps(int arr[], int n)
{
    int *jumps = new int[n];

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
            if (i <= arr[j] + j && jumps[j] != INT_MAX)
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