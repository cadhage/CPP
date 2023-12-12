#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-9
const ll nx=1e5,qx=5e5;
vector<ll> adj[nx];
vector<ll> v(nx,0);
stack<int> st;
void topo(int i,int n){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			topo(it,n);
		}
	}
	st.push(i);
} 
int main()
{
	ll n;cin>>n;
	assert(n<=nx);
	for(ll i=0;i<n-1;i++){
		ll x,y;cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
	}
	for(int i=0;i<6;i++){
		if(!v[i]){
			topo(i,6);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<' ';
		st.pop();
	}
	ll q;cin>>q;
	while(q--){
		int x;cin>>x;
		if(x==0){
			ll y,z;cin>>y>>z;
		}
		else{
			ll y,z;cin>>y>>z;
		}
	}
	
}
