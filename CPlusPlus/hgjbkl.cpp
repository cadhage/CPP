#include <bits/stdc++.h>
using namespace std;
void solver(string s,int n){
	int len=s.size();
	int dp[len][n];
	memset(dp,0,sizeof(dp));
	dp[0][(s[0]-'0')%n]++;
	for(int i=1;i<len;i++){
		dp[i][(s[i]-'0')%n]++;
		for(int j=0;j<n;j++){
			dp[i][j]+=dp[i-1][j];
			dp[i][(j*10+(s[i]-'0'))%n]+=dp[i-1][j];
		}
	}
	cout<<dp[len-1][0];	
}
int main(){
	string s="1234";
	int n=4;
	solver(s,n);
	return 0;
}
