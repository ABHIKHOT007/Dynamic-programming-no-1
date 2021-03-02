#include <bits/stdc++.h>
using namespace std;

//Last index of the element int he given array.

int LastIndexinarray(int arr[], int n, int idx, int x)
{
    //base case.

    if (idx == n)
    {
        return -1;
    }

    //element dosen't found
    //heating the base case and backtracking.

    int liisa = LastIndexinarray(arr, n, idx + 1, x);
    if (liisa == -1)
    {
        //element at idx.
        if (arr[idx] == x)
        {
            return idx;
        }
        else
        {
            return -1;
        }
    }

    return liisa;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Lastest index of the element int he given array is:" << LastIndexinarray(arr, n, 0, 2);
    return 0;
}