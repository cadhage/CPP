#include <bits/stdc++.h>
using namespace std;
vector<ll> v1,v;
stack<ll> st;

int main(){
	ios_base::stdio(false);
	cin.tie(0);
	ll tt;cin>>tt;
	while(tt--){
		ll n,k;cin>>n>>k;
		for(int i=0;i<n;i++){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.rbegin(),v.rend());
		for(int i=k;i<k;i++){
			if(v[i]!=v[k-1])
				break;
		}
		cout<<i<<'\n';
		v.clear();
	}
	return 0;
}
