#include <bits/stdc++.h>
using namespace std;

//partition problem.
//o(n^2)

bool CanPartitioned(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0 && sum != 0)
    {
        return false;
    }

    if (arr[n - 1] > sum)
    {
        return CanPartitioned(arr, n - 1, sum);
    }
    return CanPartitioned(arr, n - 1, sum) || CanPartitioned(arr, n - 1, sum - arr[n - 1]);
}

bool findpartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    return CanPartitioned(arr, n, sum / 2);
}

int main()
{
    int arr[] = {1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    findpartition(arr, n) ? cout << "YES" : cout << "NO";
    return 0;
}

//o(sum*n)


bool findpartition(int arr[], int n)
{
    int sum = 0;
    int i, j;

    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    bool dp[sum / 2 + n][n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = true;
    }
    for (int i = 1; i <= sum / 2; i++)
    {
        dp[i][0] = false;
    }

    for (int i = 1; i <= sum / 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - arr[j - 1]][j - 1];
            }
        }
    }

    return dp[sum / 2][n];
}

int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findpartition(arr, n) ? cout << "YES" : cout << "NO";
    return 0;
}

bool findPartition(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    if(sum%2!=0){
        return false;
    }

    bool dp[sum/2+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++){
        for(int j=sum/2;j>=arr[i];j--){
            if(dp[j-arr[i]]==1||j==arr[i]){
                dp[j]=1;
            }
        }
    }
    return dp[sum/2];
}

int main()
{
    int arr[]={1,3,3,2,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    findPartition(arr,n)?cout<<"YES":cout<<"NO";
    return 0;
}