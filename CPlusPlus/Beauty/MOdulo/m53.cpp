#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
pair<ll,ll> CountBits(ll n){
	ll count=0,un=0;
	for(ll i=n;i!=0;i>>=1){
		if(1&i){
			count++;
		}
		else un++;
	}
	return {count,un};
}
int main() 
{ 
    int tt;cin>>tt;
    ll sum=0;
    while(tt--){
    	ll s;cin>>s;
		pair<ll,ll> x=CountBits(s);
		sum+=__gcd(x.first,x.second);
		cout<<sum<<'\n';
	}
    return 0;
} 

