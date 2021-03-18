#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

//minimum cost path in the 2-D matrix
//recursive solution

int min(int x, int y, int z)
{
    if (x < y)
    {
        return (x < z) ? x : z;
    }
    else
    {
        return (y < z) ? y : z;
    }
}


int mincost(int arr[R][C], int m, int n)
{
    if (n < 0 || m < 0)
    {
        return INT_MAX;
    }
    else if (m == 0 && n == 0)
    {
        return arr[m][n];
    }
    else
    {
        return arr[m][n] + min(mincost(arr, m - 1, n - 1), mincost(arr, m - 1, n), mincost(arr, m, n - 1));
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3},
                     {4, 8, 2},
                     {1, 5, 3}};
    cout << mincost(arr, 2, 2);
    return 0;
}
