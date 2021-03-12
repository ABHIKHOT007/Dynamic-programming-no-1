#include <bits/stdc++.h>
using namespace std;

//recursive apporach.
//expoential time complexity.
/*
unsigned long long int dp[101][501];

unsigned long long int countdigit(int n, int sum)
{
	if(n==0){
		return sum==0;
	}

	if(dp[n][sum]!=-1){
		return dp[n][sum];
	}

	unsigned long long int ans=0;

	for(int i=0;i<10;i++){
		if(sum-i>=0){
			ans+=countdigit(n-1,sum-i);
		}
	}
	return dp[n][sum]=ans;
}

unsigned long long int finalcount(int n, int sum)
{
	memset(dp,-1,sizeof(dp));
	unsigned long long int ans=0;
	for(int i=1;i<=9;i++){
		if(sum-i>=0){
			ans+=countdigit(n-1,sum-i);
		}
	}
	return ans;
}

int main()
{
	int n=3;
	int sum=5;
	cout<<finalcount(n,sum);
	return 0;
}
*/

//O(n) time complexity.
//O(1) auxiliary space.

void CountDigit(int n, int sum)
{
	int start = pow(10, n - 1);
	int end = pow(10, n) - 1;

	int count = 0;
	int i = start;

	while (i <= end)
	{
		int curr = 0;
		int temp = i;

		while (temp != 0)
		{
			curr = temp % 10;
			temp = temp / 10;
		}
		if (curr == sum)
		{
			count++;
			i += 9;
		}
		else
		{
			i++;
		}
	}
	cout << count;
}

int main()
{
	int n = 3;
	int sum = 5;
	CountDigit(n, sum);
	return 0;
}