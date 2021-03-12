#include <bits/stdc++.h>
using namespace std;

//count ways to group the substring with given constrains.
//recursive apporach.
/*
int countNoofGroups(int pos, int last_sum, int n,char *str)
{
    if(pos==n){
        return 1;
    }

    int res=0;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=(str[i]-'0');
        if(sum>=countNoofGroups(i+1,sum,n,str)){
            res+=countNoofGroups(i+1,sum,n,str);
        }
    }
    return res;
}

int main()
{
    char str[]="1119";
    int n=strlen(str);
    cout<<countNoofGroups(0,0,n,str);
    return 0;
}
*/

const int MAX = 40;

int dp[MAX][9 * MAX + 1];

int countNoofgrpups(int pos, int last_sum, int n, char *str)
{
    if (pos == n)
    {
        return 1;
    }
    if (dp[pos][last_sum] != -1)
    {
        return dp[pos][last_sum];
    }

    dp[pos][last_sum] = 0;
    int res = 0;
    int sum = 0;

    for (int i = pos; i < n; i++)
    {
        sum += (str[i] - '0');

        if (sum >= last_sum)
        {
            res += countNoofgrpups(i + 1, sum, n, str);
        }
    }
    dp[pos][last_sum] = res;

    return res;
}

int main()
{
    char str[] = "1119";
    int n = strlen(str);

    memset(dp, -1, sizeof(dp));
    cout << countNoofgrpups(0, 0, n, str);
    return 0;
}