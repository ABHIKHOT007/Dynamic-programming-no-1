#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

//No of tree possible with given height of the tree.
//standard recursive apporach.
//time complexity will be exponential.
/*
int CountNoOftrees(int h)
{
    if(h==0||h==1){
        return 1;
    }
    return CountNoOftrees(h-1)*(2*CountNoOftrees(h-2)+CountNoOftrees(h-1));
}
*/
//More efficent apporach

long long int CountNoOftrees(int h)
{
    long long int dp[h + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod);
    }
    return dp[h];
}

int main()
{
    int h = 3;
    cout << "No of possible trees with given heigth of the tree is:" << CountNoOftrees(h);
    return 0;
}
