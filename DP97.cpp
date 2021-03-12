#include <bits/stdc++.h>
using namespace std;

//Combination of r elements int the array.
//Recursive apporach.

void combinationUtil(int arr[], int dp[], int start, int end, int index, int r)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            cout << dp[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i <= end && end - i + 1 >= r; i++)
    {
        dp[index] = arr[i];
        combinationUtil(arr, dp, i + 1, end, index + 1, r);
    }
}

void printcombination(int arr[], int n, int r)
{
    int dp[n];
    combinationUtil(arr, dp, 0, n - 1, 0, r);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printcombination(arr, n, r);
    return 0;
}