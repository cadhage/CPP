#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int n){
	dp[0]=1;
	for(int i=1;i<=n;i++)
			dp[i]=1+dp[i-dp[dp[i-1]]];
	return dp[n];
}
int main(){
	cout<<solver(9);
	return 0;
}
