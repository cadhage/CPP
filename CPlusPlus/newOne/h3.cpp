#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lcm(a,b) ((a*b)/__gcd(a,b))
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	ll ans=1;
	for(int i=0;i<m;i++){
		ans=(ans*2)%MOD;
		cout<<ans<<'\n';
	}
	for(int i=0;i<m-1;i++){
		ans=(ans*(n+1))%MOD;
		cout<<ans<<'\n';
	}
	ans=(ans*(n-m+1))%MOD;
	cout<<ans;
	return 0;
}
