#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll CountBits(ll n){
	ll count=0;
	for(ll i=n;i!=0;i>>=1){
		if(1&i){
			count++;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll l,r;cin>>l>>r;
		cout<<(CountBits(l^r))<<'\n';
	}
	return 0;
}
