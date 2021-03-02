
#include <bits/stdc++.h>
using namespace std;

//Longest common repetted subsequence.
/*
int max(int x, int y)
{
    return (x > y) ? x : y;
}

int LCRS(string X, string Y, string ori, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (X[m - 1] == Y[n - 1] && ori[m - 1] != ori[n - 1])
    {
        return 1 + LCRS(X, Y, ori, m - 1, n - 1);
    }
    else
    {
        return max(LCRS(X, Y, ori, m, n - 1), LCRS(X, Y, ori, m - 1, n));
    }
}

int lcsr(string str, int n)
{
    string ex = str;
    reverse(ex.begin(), ex.end());

    return LCRS(str, ex, str, n, n);
}

int main()
{
    char str[] = "aab";
    int n = strlen(str);
    cout << lcsr(str, n);
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

//Memoization apporach.
//o(n*n)


int LongestCommonRepetingSequence(string str)
{
    int n = str.length();

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string str = "aabb";
    cout << "Longest common repeating subsequence that repeats itself is:" << LongestCommonRepetingSequence(str) << "\n";
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

//recursive apporach.
//Expoential time.

int dp[1000][1000];

int LongestrepeatingSequence(string X, int m, int n)
{
    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if(m==0||n==0){
        return dp[m][n]=0;
    }

    if(X[m-1]==X[n-1] && m!=n){
        return dp[m][n]=LongestrepeatingSequence(X,m-1,n-1)+1;
    }
    return dp[m][n]=max(LongestrepeatingSequence(X,m,n-1),LongestrepeatingSequence(X,m-1,n));
}

int main()
{
    string str="aabb";
    int m=str.length();

    memset(dp,-1,sizeof(dp));
    cout<<"lenght of the longest repeating sequence is:"<<LongestrepeatingSequence(str,m,m);
    return 0;
}