#include <bits/stdc++.h>
using namespace std;

//maximm possible sum in contigous subarray.
//o(n)

int maxSum(int arr[], int n)
{
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        if (max_ending_here > max_so_far)
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
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum possible sum of contigous subarray is:" << maxSum(arr, n);
    return 0;
}