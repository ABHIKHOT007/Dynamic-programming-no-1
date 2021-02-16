#include <bits/stdc++.h>
using namespace std;

//counting all possible path in matrix of size m and n.
//standard recursive apporach
/*
int countPossiblePath(int m,int n)
{
    if(m==1 || n==1){
        return 1;
    }

    return countPossiblePath(m-1,n)+countPossiblePath(m,n-1);
}
*/

int countPossiblePath(int m, int n)
{
    int dp[m][n];

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m = 2;
    int n = 2;
    cout << countPossiblePath(m, n);
    return 0;
}