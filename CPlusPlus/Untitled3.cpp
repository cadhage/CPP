#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int presum[100][100];
int possibleWays(int n,int m,int k){
for(int i=1;i<=n;i++){
		dp[0][i]=0;
		presum[0][i]=1;
	}
	for(int i=0;i<=m;i++)
		presum[i][0]=dp[i][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=presum[i-1][j];
			if(j>k)
				dp[i][j]-=presum[i-1][j-k-1];
		}
		for(int j=1;j<=n;j++){
			presum[i][j]=dp[i][j]+presum[i][j-1];
		}
	}
	return dp[m][n];
}
int main(){
	int n=3,m=3,k=2;
	cout<<possibleWays(n,m,k);
	return 0;
}
