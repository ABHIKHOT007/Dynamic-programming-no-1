#include <bits/stdc++.h>
using namespace std;

//Maximum sum of non-overlapping contigous sub-arrays of k size.
//O(n*k)

void maxSubarraySumSfSizek(int arr[], int n, int k)
{
    for (int m = 0; m < k; m++)
    {
        int max_so_far = numeric_limits<int>::min();
        int max_ending_here = 0;

        int start = 0;
        int end = 0;
        int s = 0;

        for (int i = 0; i < n; i++)
        {
            max_ending_here += arr[i];
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        cout << "max_sum: " << max_so_far << " "
             << "startindex:" << start << " "
             << "end index:" << end << "\n";

        for (int j = start; j <= end; j++)
        {
            arr[j] = numeric_limits<int>::min();
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    maxSubarraySumSfSizek(arr, n, k);
    return 0;
}