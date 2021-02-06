#include <bits/stdc++.h>
using namespace std;

//max gold mine problem o(m*n)

const int MAX = 100;

int getmaxgold(int gold[][MAX], int m, int n)
{
    int goldtable[m][n];
    memset(goldtable, 0, sizeof(goldtable));

    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row <= n; row++)
        {
            int right = (col == n - 1) ? 0 : goldtable[row][col + 1];
            int right_up = (row == 0 || col == n - 1) ? 0 : goldtable[row - 1][col + 1];
            int right_down = (row == m - 1 || col == n - 1) ? 0 : goldtable[row + 1][col + 1];

            goldtable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
        }
    }

    int res = goldtable[0][0];
    for (int i = 1; i < m; i++)
    {
        res = max(res, goldtable[i][0]);
    }
    return res;
}

int main()
{
    int gold[MAX][MAX] = {{1, 3, 1, 5},
                          {2, 2, 4, 1},
                          {5, 0, 2, 3},
                          {0, 6, 1, 2}};
    int m = 4;
    int n = 4;
    cout << getmaxgold(gold, m, n);
    return 0;
}
