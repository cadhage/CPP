#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for(;i<n;i++)
#define repr(i,n) for(ll i==n-1;i>=0;i--)
ll countEggs(ll e,ll f){
	ll dp[e+1][f+1];
	ll i=1;
	rep(i,e+1){
		dp[i][0]=0;
		dp[i][1]=0;
	}
	i=1;
	rep(i,f+1){
		dp[1][i]=i;
	}
	i=2;
	ll j=2;
	rep(i,e+1){
		rep(j,f+1){
			dp[i][j]=INT_MAX;
			ll temp;
			for(ll k=0;k<=j;k++){
				temp=1+max(dp[i-1][k-1],dp[i][j-k]);
				dp[i][j]=min(temp,dp[i][j]);
			}
		}
		}
	return dp[e][f];
}
int main(){
	ll f=10,e=2;
	cout<<countEggs(e,f);
}
