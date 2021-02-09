#include <bits/stdc++.h>
using namespace std;

int maxsum(int arr[], int n)
{
    int max_sum = INT_MAX;

    int MSIBS[n];
    int MSDBS[n];

    for (int i = 0; i < n; i++)
    {
        MSDBS[i] = arr[i];
        MSIBS[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j] && MSIBS[i] < MSIBS[j] + arr[i])
            {
                MSIBS[i] = MSIBS[j] + arr[i];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            MSDBS[i] = MSDBS[j] + arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, (MSDBS[i] + MSIBS[i] - arr[i]));
    }

    return max_sum;
}

int main()
{
    int arr[] = {1, 15, 51, 45, 33, 100, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "maximum sum is:" << maxsum(arr, n);
    return 0;
}