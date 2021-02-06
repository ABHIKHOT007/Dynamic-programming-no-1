#include <bits/stdc++.h>
using namespace std;

//coint change problem
//it has both optimal substructur and overlapping subproblem property.
/*
int count(int arr[], int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (m == 0 && n >= 1)
    {
        return 0;
    }

    return count(arr, m - 1, n) + count(arr, m, n - arr[m - 1]);
}
*/
/*
int count(int arr[], int m, int n)
{
    int i, j, x, y;

    int table[n + 1][m];

    for (int i = 0; i < m; i++)
    {
        table[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = (i - arr[j] >= 0) ? table[i - arr[j]][i] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}*/

int count(int arr[], int m, int n)
{
    int table[n + 1];
    memset(table, 0, sizeof(table));
    table[0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = arr[i]; j <= n; j++)
        {
            table[j] += table[j - arr[i]];
        }
    }
    return table[n];
}

int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    cout << "no of ways are:" << count(arr, m, 4);
    return 0;
}