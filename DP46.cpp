#include <bits/stdc++.h>
using namespace std;

//Longest common increasing sequence.
//o(m*n)

int LCIS(int arr1[], int arr2[], int n, int m)
{
    int dp[m];
    for (int j = 0; j < m; j++)
    {
        dp[j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int current = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (current + 1 > dp[j])
                {
                    dp[j] = current + 1;
                }
            }
            if (arr1[i] > arr2[j])
            {
                if (dp[j] > current)
                {
                    current = dp[j];
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        if (dp[i] > result)
        {
            result = dp[i];
        }
    }
    return result;
}

int main()
{
    int arr1[] = {3, 4, 9, 1};
    int arr2[] = {5, 3, 8, 9, 10, 2, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    cout << LCIS(arr1, arr2, n, m);
    return 0;
}