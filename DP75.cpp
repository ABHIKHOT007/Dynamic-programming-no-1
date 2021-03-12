#include <bits/stdc++.h>
using namespace std;

//o(longn)

struct job
{
    int start, finish, profit;
};

bool comparator(job j1, job j2)
{
    return (j1.finish < j2.finish);
}

int BinarySearch(job jobs[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[n].start)
        {
            if (jobs[mid + 1].finish <= jobs[n].start)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int maxProfit(job arr[], int n)
{
    sort(arr, arr + n, comparator);
    int *dp = new int[n];
    dp[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inclProfit = arr[i].profit;
        int l = BinarySearch(arr, i);
        if (l != -1)
        {
            inclProfit += dp[l];
        }
        dp[i] = max(inclProfit, dp[i - 1]);
    }
    int result = dp[n - 1];
    delete[] dp;
    return result;
}

int main()
{
    job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, n);
    return 0;
}