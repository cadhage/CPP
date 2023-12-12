#include <bits/stdc++.h>
using namespace std;
bool canVote(int a[],int x,int n){
	int dp[n+1][x+1];
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(a[i]<=j){
				dp[i][j]=max(dp[i-1][j],a[i]+dp[i-1][j-a[i]]);
			}
			else 
			dp[i][j]=dp[i-1][j];
		}
	}
	return sum-dp[n][x]<=x;
}
int main(){
	int n=3,x=4;
	int a[]={2,4,2};
	canVote(a,4,n)?cout<<"yes":cout<<"no";
	return 0;
}
