#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int hosayo(int n,int m){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if((i==0 && j==0)||(i==1 &&j==0)||
			(i==1 && j==1)||(i==2||j==2))
				dp[i][j]=1;
			else if(i>j)
				dp[i-1][j]+dp[i-2][j];
			else
				dp[i][j]=dp[i-1][j-1]+dp[n-2][j-2];
		}
	}
	return dp[n][m];
}
void solver(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<hosayo(i,j)<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	solver(n);
	return 0;
}
