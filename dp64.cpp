#include <bits/stdc++.h>
using namespace std;

//using some modification of % operator in kadan's aglorithm.

int maxSumconcancatenated(int arr[], int n, int k)
{
    int max_ending_here = 0;
    int max_so_far = 0;
    for (int i = 0; i < n * k; i++)
    {
        max_ending_here += arr[i % n];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main()
{
    int arr[] = {10, 20, -30, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "maximum contigous sum is:" << maxSumconcancatenated(arr, n, k);
    return 0;
}