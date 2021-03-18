#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 3

int maxpointCollected(int arr[][M])
{
    int p1S[M + 1][N + 1];
    int p1E[M + 1][N + 1];
    memset(p1S, 0, sizeof(p1S));
    memset(p1E, 0, sizeof(p1E));

    int p2S[M + 1][N + 1];
    int p2E[M + 1][N + 1];
    memset(p1E, 0, sizeof(p2S));
    memset(p2E, 0, sizeof(p2E));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            p1S[i][j] = max(p1S[i - 1][j], p1S[i][j - 1] + arr[i - 1][j - 1]);
        }
    }

    for (int i = N; i >= 1; i--)
    {
        for (int j = M; j >= 1; j--)
        {
            p1E[i][j] = max(p1E[i + 1][j], p1E[i][j + 1] + arr[i - 1][j - 1]);
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int op1 = p1S[i][j - 1] + p1E[i][j + 1] + p2S[i + 1][j] + p2E[i - 1][j];
            int op2 = p1S[i - 1][j] + p1E[i + 1][j] + p2S[i][j - 1] + p2E[i][j + 1];
            ans = max(ans, max(op1, op2));
        }
    }
    return ans;
}

int main()
{
    int arr[][M] = {{100, 100, 100},
                    {100, 1, 100},
                    {100, 100, 100}};
    cout << maxpointCollected(arr);
    return 0;
}