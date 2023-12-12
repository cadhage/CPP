#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int solver(int price[],int n){
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int mx=INT_MIN;
		for(int j=0;j<i;j++){
			mx=max(mx,price[j]+dp[i-j-1]);
		}
		dp[i]=mx;
	}
	return dp[n];
}
int main(){
	int a[]={1,5,8,9,10,17,17,20};
	int n=sizeof a/sizeof(a[0]);
	cout<<solver(a,n);
	return 0;
}
