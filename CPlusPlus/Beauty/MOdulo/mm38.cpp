#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0};
int solver(int m,int n){
	for(int i=0;i<=m;i++){
		dp[i][0]=1;
	}
	for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(i<j){
				dp[i][j]=0;
			}
			else dp[i][j]=dp[i-1][j]+dp[i/2][j-1];
		}
	return dp[m][n];
}
int main(){
	cout<<solver(5,2);
	return 0;
}
