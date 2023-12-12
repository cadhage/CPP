#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll getFirst(ll n){
	ll c=0;
	for(int i=n;i!=0;i>>=1){
		if(i&1){
			return c;
		}
		c++;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll n;
		cin>>n;
		ll a[n];
		ll sm=0; 
		for(ll i=0;i<n;i++){
			ll x;cin>>x;
			ll first=getFirst(x);
			//cout<<first;
			sm+=pow(2,first);	
		}
		cout<<sm<<'\n';
	}
	return 0;
}
