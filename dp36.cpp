#include<bits/stdc++.h>
using namespace std;

//o(n^2)


int maxSum(int arr[], int n)
{
    int i, j, max = 0;
    int msis[n];

    for (int i = 0; i < n; i++)
    {
        msis[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
            {
                msis[i] = msis[j] + arr[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max < msis[i])
        {
            max = msis[i];
        }
    }
    return max;
}

int main()
{
}