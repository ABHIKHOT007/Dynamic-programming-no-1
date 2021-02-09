#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//maximum product of increasing subsequence.

ll productofsequence(int arr[], int n)
{
    ll mpis[n];

    for (int i = 0; i < n; i++)
    {
        mpis[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i]))
            {
                mpis[i] = mpis[j] * arr[i];
            }
        }
    }
    return *max_element(mpis, mpis + n);
}

int main()
{
    int arr[] = {3, 100, 4, 5, 150, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "maximum product of the increasing sequence is:" << productofsequence(arr, n) << "\n";
    return 0;
}