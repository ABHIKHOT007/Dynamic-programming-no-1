#include <bits/stdc++.h>
using namespace std;

//Minimum XOr value pair in array.
//O(N^2) time complexity.
//O(N) auxiliary space.
/*
int MinXORValuePair(int arr[], int n)
{
    int min_XOR =INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr_XOR = arr[i] ^ arr[j];
            min_XOR = min(min_XOR, curr_XOR);
        }
    }
    return min_XOR;
}
*/

//O(N*logN)
//O(1) auxiliary space.

int MinXORValuePair(int arr[], int n)
{
    sort(arr,arr+n);
    int min_XOR=INT_MAX;
    int val=0;

    for(int i=0;i<n-1;i++){
        val=arr[i]^arr[i+1];
        min_XOR=min(min_XOR,val);
    }
    return min_XOR;
}

int main()
{
    int arr[] =  {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MinXORValuePair(arr, n);
    return 0;
}