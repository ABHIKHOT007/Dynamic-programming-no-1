#include <bits/stdc++.h>
using namespace std;

//o(n^2)

int findSum(vector<int> arr)
{
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }
    return sum;
}

void PrintIncreasingSum(int arr[], int n)
{
    vector<vector<int>> dp(n);
    dp[0].push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && (findSum(dp[i]) < findSum(dp[j])))
            {
                dp[i] = dp[j];
            }
        }
    }

    vector<int> res = dp[0];
    for (vector<int> x : dp)
    {
        if (findSum(x) > findSum(res))
        {
            res = x;
        }
    }

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 2, 6, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    PrintIncreasingSum(arr, n);
    return 0;
}
