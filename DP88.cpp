#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

//o(R*C)

int countpath(int arr[][C])
{
    if (arr[0][0] == -1)
    {
        return 0;
    }

    for (int i = 0; i < R; i++)
    {
        if (arr[i][0] == 0)
        {
            arr[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i < C; i++)
    {
        if (arr[0][i] == 0)
        {
            arr[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (arr[i][j] == 1)
            {
                continue;
            }
            if (arr[i - 1][j] > 0)
            {
                arr[i][j] = (arr[i][j] + arr[i - 1][j]);
            }
            if (arr[i][j - 1] > 0)
            {
                arr[i][j] = (arr[i][j] + arr[i][j - 1]);
            }
        }
    }
    return (arr[R - 1][C - 1] > 0) ? arr[R - 1][C - 1] : 0;
}

int main()
{
    int arr[R][C] = {{0, 0, 0, 0},
                     {0, -1, 0, 0},
                     {-1, 0, 0, 0},
                     {0, 0, 0, 0}};
    cout << countpath(arr);
    return 0;
}