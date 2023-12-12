#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll countCoin(ll a[],ll n,ll total){
	ll dp[n+1][total+1];
	for(ll i=0;i<=n;i++)
		dp[i][0]=1;
	for(ll i=1;i<=total;i++)
		dp[0][i]=0;
	ll x,y;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=total;j++){
			if(a[i-1]<=j)
				dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][total];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll total;
	cin>>total;
	cout<<countCoin(a,n,total)<<'\n';
}
