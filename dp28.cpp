#include <bits/stdc++.h>
using namespace std;
/*
int totalnosequence(int m, int n)
{
    if (m < n)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return totalnosequence(m - 1, n) + totalnosequence(m / 2, n - 1);
}*/

//o(m*n)


int totalnosequence(int m, int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (i > j)
            {
                t[i][j] = 0;
            }
            else if (j == 1)
            {
                t[i][j] = i;
            }
            else
            {
                t[i][j] = t[i - 1][j] + t[i / 2][j - 1];
            }
        }
    }
    return t[m][n];
}

int main()
{
    int m = 10;
    int n = 4;
    cout << "total number of possible sequence are:" << totalnosequence(m, n) << "\n";
    return 0;
}