#include<bits/stdc++.h>
using namespace std;

//Count Dearrangemtnts of the given string of lenght n.
//recursive apporach
//expoential time complexity.

/*
int countDearrangement(int n)
{
    if(n==0||n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    return (n-1)*(countDearrangement(n-1)+countDearrangement(n-2));
}
*/

//O(N) time complexity.
//O(N) auxillary space.

/*
int countDearrangement(int n)
{
    int dp[n+1]={0};
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;++i){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
*/

//O(N) time complexity.
//O(1) Auxillary space.

int countDearrangement(int n)
{
    if(n==1||n==2){
        return n-1;
    }
    int a=0;
    int b=1;

    for(int i=3;i<=n;i++){
        int c=(i-1)*(a+b);
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    int n=4;
    cout<<countDearrangement(n);
    return 0;
}

