#include <bits/stdc++.h>
using namespace std;

int dp[10001][15001];

//o(N^2*24)
//Auxiliary space o(10^7)


void computeArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 15000; j++)
		{
			if (i == 0)
			{
				dp[i][j] = (j == arr[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + (arr[i] == j);
			}
		}
	}
}

int countTriplates(int arr[], int n)
{
	computeArray(arr, n);

	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = 1; k <= 24; k++)
			{
				int cube = k * k * k;
				int rem = cube - (arr[i] + arr[j]);
				if (rem > 0)
				{
					ans += dp[n - 1][rem] - dp[j][rem];
				}
			}
		}
	}
	return ans;
}

int main()
{
	int arr[] = {2, 5, 1, 20, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countTriplates(arr, n);
	return 0;
}