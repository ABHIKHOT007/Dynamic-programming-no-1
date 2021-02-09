#include <bits/stdc++.h>
using namespace std;
#define N 4
//maximum sum of the triangle is.

int maxSum(int arr[][N], int m, int n)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i + 1][j] > arr[i + 1][j + 1])
            {
                arr[i][j] += arr[i + 1][j];
            }
            else
            {
                arr[i][j] += arr[i + 1][j + 1];
            }
        }
    }
    return arr[0][0];
}

int main()
{
    int arr[N][N] = {{1, 0, 0}, {4, 8, 0}, {1, 5, 3}};
    cout << "maximum sum of the elements is:" << maxSum(arr, 2, 2);
    return 0;
}