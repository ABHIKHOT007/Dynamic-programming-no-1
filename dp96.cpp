#include <bits/stdc++.h>
using namespace std;

//printing all possible path from left top to right bottom in a matrix of size m*n.

void printallPossiblePathUtil(int *arr, int i, int j, int m, int n, int *path, int pi)
{
    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
        {
            path[pi + k - j] = *((arr + i * n) + k);
        }
        for (int l = 0; l < pi + n - j; l++)
        {
            cout << path[l] << " ";
        }
        cout << endl;
        return;
    }
    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
        {
            path[pi + k - i] = *((arr + k * n) + j);
        }
        for (int l = 0; l < pi + m - i; l++)
        {
            cout << path[l] << " ";
        }
        cout << endl;
    }
    path[pi] = *((arr + i * n) + j);
    printallPossiblePathUtil(arr, i + 1, j, m, n, path, pi + 1);
    printallPossiblePathUtil(arr, i, j + 1, m, n, path, pi + 1);
}

void printallPossiblePath(int *arr, int m, int n)
{
    int *path = new int[m + n];
    printallPossiblePathUtil(arr, 0, 0, m, n, path, 0);
}

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printallPossiblePath(*arr, 2, 3);
    return 0;
}