#include <bits/stdc++.h>
using namespace std;
//Maximum product sub-array.
//O(N^2)
/*
int maxProduct(int arr[], int n)
{
    int result = arr[0];

    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            result = max(result, mul);
            mul *= arr[j];
        }
        result = max(result, mul);
    }
    return result;
}
*/

//O(N) time complexity.
//O(1) Auxillary space.

int maxProduct(int arr[], int n)
{
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);
            flag = 1;
        }
        else if (arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else
        {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }
    if (flag == 0 && max_so_far == 0)
    {
        return 0;
    }
    return max_so_far;
}

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProduct(arr, n);
    return 0;
}