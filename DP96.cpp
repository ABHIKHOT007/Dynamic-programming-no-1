#include <bits/stdc++.h>
using namespace std;

//Printing the subset of the given set of the given size k.

void CombinationUtil(int arr[], int n, int r, int index, int dp[], int i)
{
   

    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            cout << dp[j] << " ";
           
        }
        cout << "\n";
    }

    if (i >= n)
    {
        return;
    }

    dp[index] = arr[i];
    CombinationUtil(arr, n, r, index + 1, dp, i + 1);
    CombinationUtil(arr, n, r, index, dp, i + 1);
}

void printcombiation(int arr[], int n, int r)
{
    int dp[r];
    CombinationUtil(arr, n, r, 0, dp, 0);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    printcombiation(arr, n, 3);
    return 0;
}
