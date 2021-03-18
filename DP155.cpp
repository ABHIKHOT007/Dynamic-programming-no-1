#include <bits/stdc++.h>
using namespace std;

//minimum no jumps required to reach end of the array.
//recursive apporach.
//O(N*N)

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
}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n);
    return 0;
}