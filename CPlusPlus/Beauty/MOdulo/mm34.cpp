#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int n){
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n;i++)
		dp[i]=dp[dp[i-1]]+dp[i-dp[i-1]];
	return dp[n];
}
int main(){
	cout<<solver(10);
	return 0;
}
