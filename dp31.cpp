#include <bits/stdc++.h>
using namespace std;

//longest increasing subsequence.
/*
int lcsincreasing(int arr[], int n, int *max_ref)
{
    if (n == 1)
    {
        return 1;
    }

    int res, max_ending = 1;

    for (int i = 1; i < n; i++)
    {
        res = lcsincreasing(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending)
        {
            max_ending = res + 1;
        }
        if (*max_ref < max_ending)
        {
            *max_ref = max_ending;
        }
    }
    return max_ending;
}

int lcs(int arr[], int n)
{
    int max = 1;
    lcsincreasing(arr, n, &max);
    return max;
}

int main()
{
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<lcs(arr,n);
    return 0;
}*/

//o(n^2)

int lcs(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis, lis + n);
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"length of sequence is:"<<lcs(arr,n)<<"\n";
    return 0;
}