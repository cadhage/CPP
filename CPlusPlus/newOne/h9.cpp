#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
ll MOD=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll k,n,ans=0,p=1;
		cin>>k>>n;
		while(p<=n)
		{
			ans++;
		
			p+=p*k;
			//cout<<p<<'\n';
		}
			cout<<ans<<"\n";
	}
	return 0;
}
