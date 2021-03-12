#include <bits/stdc++.h>
using namespace std;

//Recursive apporach.
/*
unsigned long long int countDigitUtil(int n, int sum)
{
    if(n==0){
        return sum==0;
    }

    if(sum==0){
        return 1;
    }
    if(sum==0){
        return 1;
    }

    unsigned long long int ans=0;

    for(int i=0;i<=9;i++){
        if(sum-i>=0){
            ans+=countDigitUtil(n-1,sum-i);
        }
    }
    return ans;
}

unsigned long long int CountDigit(int n, int sum)
{
    unsigned long long int ans=0;

    for(int i=1;i<=9;i++){
        if(sum-i>=0){
            ans+=countDigitUtil(n-1,sum-i);
        }
    }
    return ans;
}

int main()
{
    int n=2;
    int sum=5;
    cout<<CountDigit(n,sum);
    return 0;
}
*/

unsigned long long int dp[101][501];

unsigned long long int CountDigit(int n, int sum)
{
    if (n == 0)
    {
        return sum == 0;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    unsigned long long int ans = 0;

    for (int i = 0; i < 10; i++)
    {
        if (sum - i >= 0)
        {
            ans += CountDigit(n - 1, sum - 1);
        }
    }
    return dp[n][sum] = ans;
}

unsigned long long count(int n, int sum)
{
    memset(dp, -1, sizeof(dp));
    unsigned long long int ans = 0;

    for (int i = 1; i <= 9; i++)
    {
        if (sum - i >= 0)
        {
            ans += CountDigit(n - 1, sum - i);
        }
    }
    return ans;
}
int main()
{
    int n = 3;
    int sum = 5;
    cout << count(n, sum);
    return 0;
}
