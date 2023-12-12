#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0,c=0,mx=INT_MIN,cn=0; 
    for (ll i = 0; i <n; i++) 
    { 
    	if(a[i]>=0){
        	ans+=a[i];
        	c++;
		}
		mx=max(a[i],mx);
    }  
    if(c==0)
    {
    	c=1;ans=mx;
	}
	cout<<ans<<' '<<c<<'\n';	
	return 0;
}
