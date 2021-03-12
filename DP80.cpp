#include<bits/stdc++.h>
using namespace std;
#define MAXA 21
#define MAXB 1000001

double dp[MAXB];

//probability of getting at least K head in N tossecess.
/*
double fact[MAX];

double probability(int k, int n)
{
    double ans=0;
    for(int i=k;i<=n;k++){
        ans+=fact[n]/(fact[i]*fact[n-i]);
    }
    ans=ans/(1LL<<n);
    return ans;
}

void preCompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<20;i++){
        fact[i]=fact[i-1]*i;
    }
}
*/

double probability(int k, int n)
{
    double ans=0;

    for(int i=k;i<=n;i++){
        double res=dp[n]-dp[i]-dp[n-1]-n;
        ans+=pow(2.0,res);
    }
    return ans;
}

void preCompute()
{
    for(int i=2;i<MAXB;i++){
        dp[i]=log2(i)+dp[i-1];
    }
}

int main()
{
    preCompute();
    cout<<probability(2,3)<<"\n";
    cout<<probability(3,6)<<"\n";
    return 0;
}