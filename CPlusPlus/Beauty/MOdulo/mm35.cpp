#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int n){
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
		if(i%2==0)
			dp[i]=dp[i/2]*4;
		else dp[i]=dp[i/2]*4+1;
	return dp[n];
}
int main(){
	cout<<solver(15);
	return 0;
}
