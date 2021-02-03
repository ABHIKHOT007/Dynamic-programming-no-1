#include <bits/stdc++.h>
using namespace std;

//Binomial coefficent problem.
/*
int Binomial(int n, int k)
{
    int res = 0;
    if (k > n)
    {
        return 0;
    }
    if (k == 0 || k == n)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        res = Binomial(n - 1, k - 1) + Binomial(n - 1, k);
    }
    return res;
}

int main()
{
    int n = 5;
    int k = 2;
    cout << "Binomial coefficent is:" << Binomial(n, k);
    return 0;
}
*/
/*
int Binomial(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    if (k == 0 || k == n)
    {
        return 1;
    }

    return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
}

int main()
{
    int n = 5;
    int k = 2;
    cout << "value of c:" << n << " " << k << "is:" << Binomial(n, k) << endl;
    return 0;
}
*/

/*
int min(int n, int k);

int Bionmial(int n, int k)
{
    int c[n+1][k+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    return c[n][k];
}

int min(int a, int b)
{
    return (a<b)?a:b;
}

int main()
{
    int n = 5;
    int k = 2;
    cout << "value of:" << n << " " << k << "is:" << Bionmial(n, k) << endl;
    return 0;
}
*/

int Bionmial(int n, int k, int **dp)
{
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    if (k == 0)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }
    if (k == n)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }
    dp[n][k] = Bionmial(n - 1, k - 1, dp) + Bionmial(n - 1, k, dp);
    return dp[n][k];
}

int BionmialUtil(int n, int k)
{
    int **dp;
    dp = new int *[n + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[k + 1];
    }
    for (int i = 0; i < (n + 1); i++)
    {
        dp[i] = new int[k + 1];
    }
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (k + 1); j++)
        {
            dp[i][j] = -1;
        }
    }
    return Bionmial(n, k, dp);
}

int main()
{
    int n = 5;
    int k = 2;
    cout << "value of:" << n << " " << k << "is:" << BionmialUtil(n, k) << endl;
    return 0;
}