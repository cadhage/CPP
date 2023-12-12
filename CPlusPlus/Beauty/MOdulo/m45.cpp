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
		ll n;cin>>n;
		ll x=CountBits(n);
		ll y=CountBits(n);
		int i=0,res=0;
		while(y>=x){
			i++;
			y=CountBits(n+i);
			cout<<n+i<<' ';
			if(y>x)
				break;
		}
		cout<<'\n';
	}
	return 0;
}
