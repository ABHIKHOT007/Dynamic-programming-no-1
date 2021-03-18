#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3


int min(int x, int y, int z)
{
    if(x<y){
        return (x<z)?x:z;
    }
    else{
        return (y<z)?x:z;
    }
}

int minCoat(int arr[][C], int m, int n)
{
    int dp[R][C];
    dp[0][0]=arr[0][0];

    for(int i=1;i<=m;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }    
    for(int j=1;j<=n;j++){
        dp[0][j]=dp[0][j-1]+arr[j][0];
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    int arr[R][C]= {{1, 2, 3},
                     {4, 8, 2},
                     {1, 5, 3}};
    cout<<minCoat(arr,2,2);
    return 0;
}