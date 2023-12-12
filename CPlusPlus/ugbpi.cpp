#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int coinChange(ll a[],ll n,ll total){
	if(total==0)
		return 1;
	if(total<0)
		return 0;
	if(n<=0 &&total>=1 )
		return 0;
	return coinChange(a,n-1,total)+coinChange(a,n,total-a[n-1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll total;cin>>total;
	cout<<coinChange(a,n,total)<<endl;
	return 0;
}
