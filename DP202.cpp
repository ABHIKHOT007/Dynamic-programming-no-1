#include<bits/stdc++.h>
using namespace std;

/*
int eggDrop(int n, int k)
{
	if(n==1){
		return k;
	}

	if(k==0||k==1){
		return k;
	}

	int ans=INT_MAX;
	int rec;

	for(int i=1;i<=k;i++){
		rec=max(eggDrop(n-1,i-1),eggDrop(n,k-i));
		ans=min(ans,rec);
	}

	return ans+1;
}
*/

int eggDrop(int n, int k)
{
	int dp[n+1][k+1];

	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}

	for(int i=1;i<=k;i++){
		dp[1][i]=i;
	}

	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				int res=1+max(dp[i-1][x-1],dp[i][j-x]);
				if(res<dp[i][j]){
					dp[i][j]=res;
				}
			}
		}
	}

	return dp[n][k];
}

int main()
{
	int n=2;
	int k=10;
	cout<<eggDrop(n,k);
	return 0;
}