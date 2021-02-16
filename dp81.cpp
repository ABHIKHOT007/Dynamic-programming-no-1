#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int countEndless(bool input[][MAX], int n)
{
    bool row[n][n];
    bool col[n][n];

    for (int j = 0; j < n; j++)
    {
        bool isEndless = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (input[i][j] == 0)
            {
                isEndless = 0;
                col[i][j] = isEndless;
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        bool isEndless = 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (row[i][j] && col[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    bool input[][MAX] = {{1, 0, 1, 1},
                         {0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    int n = 4;

    cout << countEndless(input, n);
    return 0;
}