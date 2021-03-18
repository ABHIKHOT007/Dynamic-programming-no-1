#include <bits/stdc++.h>
using namespace std;

//maximum adjcent array sum.

int maxAdjcentSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    int incl = arr[0];
    int excl = 0;
    int excl_new = 0;

    for (int i = 1; i < n; i++)
    {
        excl_new = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_new;
    }

    return (incl > excl) ? incl : excl;
}

int main()
{
    int arr[] = {5, 5, 10, 40, 50, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxAdjcentSum(arr, n);
    return 0;
}