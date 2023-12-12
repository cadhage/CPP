#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool subsetSum(ll a[],ll n,ll sum){
	bool subset[n+1][sum+1];
	for(int i=0;i<=n;i++)
		subset[i][0]=true;
	for(int i=0;i<=sum;i++)
		subset[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<a[i-1])
				subset[i][j]=subset[i-1][j];
			if(j>=a[i-1])
				subset[i][j]=subset[i-1][j]||subset[i-1][j-a[i-1]];
		}
	}
	return subset[n][sum];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll sum;cin>>sum;
	cout<<subsetSum(a,n,sum);
	return 0;
}
