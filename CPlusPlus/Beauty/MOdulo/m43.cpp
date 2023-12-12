#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool CountBits(ll n){
	ll count=0;
	if(n==1)
		return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll l,r;cin>>l>>r;
		vector<int> primes;
		for(int i=l;i<=r;i++){
			if(CountBits(i))
				primes.push_back(i);
		}
		for(auto it:primes){
		//	cout<<it<<' ';
		}
		int mn=0;
		if(primes.size()<=1)
			cout<<-1<<'\n';
		else{
			for(int i=0;i<primes.size()-2;i++){
				mn=min(primes[i]^primes[i+1],primes[i+1]^primes[i+2]);
			}
			cout<<mn<<'\n';
		}
	//	cout<<(CountBits(r))<<'\n';
	}
	return 0;
}
