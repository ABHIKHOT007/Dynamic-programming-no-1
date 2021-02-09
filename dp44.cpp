#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int a;
    int b;
};

int maxChainLength(Pair arr[], int n)
{
    int max = 0;
    int *dp = new int[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].a > arr[j].b && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i])
        {
            max = dp[i];
        }
    }
    return max;
}

int main()
{
    Pair arr[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "maximum length of the sequence is:" << maxChainLength(arr, n);
    return 0;
}