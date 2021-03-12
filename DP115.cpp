#include <bits/stdc++.h>
using namespace std;

//countzero sum triplate's in the given array.
//O(N^2)


void  ZeroSumTriplate(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            int val = -arr[i];
            if (arr[start] + arr[end] < val)
            {
                start++;
            }
            else if (arr[start] + arr[end] > val)
            {
                end--;
            }
            else
            {
                cout << arr[i] << " " << arr[start] << " " << arr[end] << "\n";
                start++;
                end--;
            }
        }
    }
}

int main()
{
    int arr[] = {0,-2,7,2,4,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    ZeroSumTriplate(arr,n);
    return 0;
}