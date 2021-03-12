#include <bits/stdc++.h>
using namespace std;

//Maximum sum subarray removing at most one elements.

int maxSubArraySum(int arr[], int n)
{
    int LR[n];
    int RL[n];

    int curr_max = arr[0], max_so_far = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
        LR[i] = curr_max;
    }

    curr_max = max_so_far = RL[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
        RL[i] = curr_max;

    }

    int fans = max_so_far;
  

    for (int i = 1; i < n - 1; i++)
    {
        fans = max(fans, LR[i - 1] + RL[i + 1]);

    }
    return fans;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubArraySum(arr, n);
    return 0;
}