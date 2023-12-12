#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll x,ans=0;cin>>x;
		fl(i,1,n){
			ll y;cin>>y;
			x=x%y;	
		}
		cout<<x<<'\n';
	}
	return 0;
}
