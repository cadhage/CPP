#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int n){
	if(n==0||n==1)
		return 0;
	int max_val=0;
	for(int i=1;i<n;i++){
		max_val=max(max_val,max(i*(n-i),solver(n-i)*i));
	}
	return max_val;
	
}
int solverDP(int n){
	dp[0]=dp[1]=0;
	for(int i=1;i<=n;i++){
		int max_val=0;
		for(int j=1;j<=i/2;j++){
			max_val=max(max_val,max((i-j)*j,dp[i-j]*j));
		}
		dp[i]=max_val;
	}
	return dp[n];
}
int main(){
	cout<<solver(10);
	cout<<'\n'<<solverDP(10);
}
