#include <bits/stdc++.h>
using namespace std;

//Max product of subarray of negative base.
//O(N) time complexity.
//O(1) space complexity.

int maxProduct(int arr[], int n)
{
    int ans = INT_MIN;
    int maxval = 1;
   int minval = 1;
    int prevmax;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            maxval = maxval * arr[i];
            minval = min(1, minval * arr[i]);
        }
        else if (arr[i] == 0)
        {
            minval = 1;
            maxval = 0;
        }
        else if (arr[i] < 0)
        {
            prevmax = maxval;
            maxval = minval * arr[i];
            minval = prevmax * arr[i];
        }
        ans = max(ans, maxval);
        if (maxval <= 0)
        {
            maxval = 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {0, -4, 0, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProduct(arr, n);
    return 0;
}