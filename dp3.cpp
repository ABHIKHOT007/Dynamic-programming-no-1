#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int dp[MAX];

//Total no ways to a number.

/*int solve(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return solve(n - 1) + solve(n - 3) + solve(n - 5);
}*/

int solve(int n)
{
    for(int i=0;i<MAX;i++){
        dp[i]=-1;
    }

    if(n<1){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=solve(n-1)+solve(n-3)+solve(n-5);
}

int main()
{
    int n = 6;
    cout << "Total no of ways to form a number is:" << solve(n) << "\n";
    return 0;
}