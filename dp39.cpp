#include <bits/stdc++.h>
using namespace std;

//maximum subsequence sum with no consecutive elements
//o(n)
/*

int maxSumOfThreeConsetive(int arr[], int n)
{
    int sum[n];

    if (n >= 1)
    {
        sum[0] = arr[0];
    }

    if (n >= 2)
    {
        sum[1] = arr[0] + arr[1];
    }
    if (n > 2)
    {
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));
    }

    for (int i = 3; i <= n; i++)
    {
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]);
    }
    return sum[n - 1];
}

*/
//recursive solution
//o(n)

int arr[] = {100, 1000, 100, 1000, 1};
int sum[10000];

int maxSumOfThreeConsetive(int n)
{
    if (sum[n] != -1)
    {
        return sum[n];
    }

    if (n == 0)
    {
        return sum[n] = 0;
    }
    if (n == 1)
    {
        return sum[n] = arr[0];
    }
    if (n == 2)
    {
        return sum[n] = arr[1] + arr[0];
    }
    return sum[n] = max(max(maxSumOfThreeConsetive(n - 1), maxSumOfThreeConsetive(n - 2) + arr[n - 1]), arr[n - 2] + arr[n - 1] + maxSumOfThreeConsetive(n - 3));
}

int main()
{
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(sum, -1, sizeof(sum));
    cout << maxSumOfThreeConsetive(n);
    return 0;
}