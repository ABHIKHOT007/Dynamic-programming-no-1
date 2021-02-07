#include <bits/stdc++.h>
using namespace std;

//rod cutting problem.

int max(int a, int b)
{
    return (a > b) ? a : b;
}

/*
int cutrod(int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int max_val = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        max_val = max(max_val, arr[i] + cutrod(arr, n - i - 1));
    }
    return max_val;
}
*/
//o(n^2)

int cutrod(int arr[], int n)
{
    int val[n + 1];
    val[0] = 0;
    int i, j;

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, arr[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "maximum cost of selling of rod is:" << cutrod(arr, n) << "\n";
    return 0;
}