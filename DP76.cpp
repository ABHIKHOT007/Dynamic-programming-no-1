#include <bits/stdc++.h>
#define R 5
#define C 5
using namespace std;

bool isValid(int i, int j)
{
    return (i >= 0 && i < R && j >= 0 && j < C);
}

/*
int maxCoinCollected(char arr[R][C], int i, int j, int path)
{
    if(isValid(i,j)==false||arr[i][j]=='#'){
        return 0;
    }

    int result=(arr[i][j]=='c')?1:0;

    if(path==1){
        return result+max(maxCoinCollected(arr,i+1,j,0),maxCoinCollected(arr,i,j+1,1));
    }

    return result+max(maxCoinCollected(arr,i+1,j,1),maxCoinCollected(arr,i,j-1,0));
}
*/

int maxCoinCollected(char arr[][C], int i, int j, int path, int dp[R][c][2])
{
    if (isValid(i, j) == false || arr[i][j] == '0')
    {
        return 0;
    }

    if (dp[i][j][path] != 1)
    {
        return dp[i][j][path];
    }

    dp[i][j][path] = (arr[i][j] == 'c') ? 1 : 0;

    if (path == 1)
    {
        dp[i][j][path] = max(maxCoinCollected(arr, i + 1, j, 1, dp), maxCoinCollected(arr, i, j - 1, 0, dp));
    }

    if (path == 0)
    {
        dp[i][j][path] = max(maxCoinCollected(arr, i + 1, j, 0, dp), maxCoinCollected(arr, i, j + 1, 1, dp));
    }

    return dp[i][j][path];
}

int main()
{
    char arr[R][C] = {{'E', 'C', 'C', 'C', 'C'},
                      {'C', '#', 'C', '#', 'E'},
                      {'#', 'C', 'C', '#', 'C'},
                      {'C', 'E', 'E', 'C', 'E'},
                      {'C', 'E', '#', 'C', 'E'}};
    cout << maxCoinCollected(arr, 0, 0, 1);
}