#include <bits/stdc++.h>
using namespace std;

//Maximum sum of the contiguous subarray
//o(n)
/*
int maxSum(int arr[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
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
*/

int maxSum(int arr[], int n)
{
    int curr_max = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < n; i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum is:" << maxSum(arr, n);
    return 0;
}