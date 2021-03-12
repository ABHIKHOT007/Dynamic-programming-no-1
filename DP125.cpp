#include <bits/stdc++.h>
using namespace std;

//kadan's algorithm for finding longest subarray sum.
//O(N)
//Kadan's algorithm is used for the largest subarray sum, we can thik like,
//total sum of all elements of the array is the max sumof subarray, but there can be negative elements in the array so use kadan's algorithm.

int maxSubarray(int arr[], int n)
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

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxsum = maxSubarray(arr, n);
    cout << maxsum;
    return 0;
}