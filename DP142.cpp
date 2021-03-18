#include <bits/stdc++.h>
using namespace std;
#define N 5
#define M 6
//maxtrix of size k in the given matrix of size n.

int matrixMAXsize(int arr[][M])
{
    int dp[N][M];
    memset(dp, sizeof(dp), 0);
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1])
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                else
                {
                    dp[i][j] = 1;
                }
            }
            result = max(result, dp[i][j]);
        }
    }
    return result;
}

int main()
{
    int arr[][M] = { {9, 9, 9, 8},
                     {9, 9, 9, 6},
                     {9, 9, 9, 3},
                     {2, 2, 2, 2}};
    cout << matrixMAXsize(arr);
    return 0;
}