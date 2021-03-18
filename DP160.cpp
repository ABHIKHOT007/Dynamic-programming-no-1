#include <bits/stdc++.h>
using namespace std;

//minimum jumps required to reach end of the array.
//O(N)

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int minJumps(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[0] == 0)
    {
        return -1;
    }

    int maxReach = arr[0];
    int step = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            return jumps;
        }
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if (step == 0)
        {
            jumps++;
            if (i >= maxReach)
            {
                return -1;
            }
            step = maxReach - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n);
    return 0;
}