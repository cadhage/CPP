#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		ll r=0,ar=0;
		ll ans=-1;
		bool flag=false;
		fl(i,0,n){
			ll x;cin>>x;
			ar=r+x;
			if(!flag &&ar-k<0){
				ans=i;
				flag=true;
				//break;
			}
			r=ar-k;	
			//cout<<r<<'\n';
		}
		if(ans==-1){
			cout<<"YES\n";
		}
		else cout<<"NO "<<ans+1<<'\n';
	}
	return 0;
}
