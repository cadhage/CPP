#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int n){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
			dp[i]=2*dp[i-1]+dp[n-2];
	return dp[n];
}
int main(){
	cout<<solver(3);
	return 0;
}
