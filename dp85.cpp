#include <bits/stdc++.h>
using namespace std;

//count number of solution of the equtions.
/*
int countsolution(int coeff[], int start, int end, int rhs)
{
    if(rhs==0){
        return 1;
    }
    int result=0;
    for(int i=start;i<=end;i++){
        if(coeff[i]<=rhs){
            result+=countsolution(coeff,i,end,rhs-coeff[i]);
        }
    }
    return result;
}


int main()
{
    int coeff[]={2,2,5};
    int rhs=4;
    int n=sizeof(coeff)/sizeof(coeff[0]);
    cout<<countsolution(coeff,0,n-1,rhs);
    return 0;
}*/

int countsolution(int coeff[], int n, int rhs)
{
    int dp[rhs + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coeff[i]; j <= rhs; j++)
        {
            dp[j] += dp[j - coeff[i]];
        }
    return dp[rhs];
}

int main()
{
    int coeff[] = {2, 2, 5};
    int rhs = 5;
    int n = sizeof(coeff) / sizeof(coeff[0]);
    cout << countsolution(coeff, n, rhs);
    return 0;
}