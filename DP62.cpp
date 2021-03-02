#include <bits/stdc++.h>
using namespace std;
#define M 3
int dp[M][M];

//Longest sum alternating subsequence.
//recursive apporach.
/*
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int MaxAlternatingSubsequence(int arr[][M], int i, int j, int n)
{
    if(i==n-1){
        return arr[i][j];
    }

    int AlterSequence=0;
    for(int k=0;k<n;k++){
        if(k!=j){
            AlterSequence=max(AlterSequence,MaxAlternatingSubsequence(arr,i+1,k,n));
        }
    }
    return AlterSequence+arr[i][j];
}

int LargetSum(int arr[][M], int n)
{
    int res=0;
    for(int j=0;j<n;j++){
        res=max(res,MaxAlternatingSubsequence(arr,0,j,n));
        return res;
    }
}

int main()
{
    int arr[M][M] = {{3, 1, 2}, {4, 8, 5}, {6, 9, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<LargetSum(arr, n);
    return 0;
}
*/

//tabulation method.

int MaxAlternatingSubSequence(int arr[][M], int i, int j, int n)
{
    if (arr[i][j] != -1)
    {
        return -1;
    }

    if (i == n - 1)
    {
        return (arr[i][j] = arr[i][j]);
    }

    int maxSum = 0;
    for (int k = 0; k < n; k++)
    {
        if (k != j)
        {
            maxSum = max(maxSum, MaxAlternatingSubSequence(arr, i + 1, k, n));
        }
    }
    return arr[i][j] = (maxSum + arr[i][j]);
}

int LargestSum(int arr[][M], int n)
{
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        res = max(res, MaxAlternatingSubSequence(arr, 0, j, n));
    }
    return res;
}