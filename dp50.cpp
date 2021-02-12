#include <bits/stdc++.h>
using namespace std;

//maximum sum of the path in the triangle.

int maxSum(int arr[][3], int n)
{
    if(n > 1)
    {
        arr[1][1] = arr[1][1] + arr[0][0];
        arr[1][0] = arr[1][0] + arr[0][0];
    }

    for (int i = 2; i < n; i++)
    {
        arr[i][0] = arr[i][0] + arr[i - 1][0];
        arr[i][i] = arr[i][i] + arr[i - 1][i - 1];
        for (int j = 1; j < i; j++)
        {
            if (arr[i][j] + arr[i - 1][j - 1] >= arr[i][j] + arr[i - 1][j])
            {
                arr[i][j] = arr[i][j] + arr[i - 1][j];
            }
            else
            {
                arr[i][j] = arr[i][j] + arr[i - 1][j];
            }
        }
    }
    int max = arr[n - 1][0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[n - 1][i])
        {
            max = arr[n - 1][i];
        }
    }
    return max;
}

int main()
{
    int arr[3][3] = {{1}, {2, 1}, {3, 3, 2}};
    cout << maxSum(arr, 3);
    return 0;
}