#include <bits/stdc++.h>
using namespace std;

//subset sum and divisible with given value
//o(m^2)

bool modualrsum(int arr[], int n, int m)
{
    if (n > m)
    {
        return true;
    }

    bool dp[m];
    memset(dp, false, m);

    for (int i = 0; i < n; i++)
    {
        if (dp[0])
        {
            return true;
        }

        bool temp[m];
        memset(temp, false, m);
        for (int j = 0; j < m; j++)
        {
            if (dp[j] == true)
            {
                if (dp[(j + arr[i]) % m] == false)
                {
                    temp[(j + arr[i]) % m] = true;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (temp[j])
            {
                dp[j] = true;
            }
        }
    }
    return dp[0];
}

int main()
{
    int arr[] = {1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int m = 5;
    modualrsum(arr, n, m) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}