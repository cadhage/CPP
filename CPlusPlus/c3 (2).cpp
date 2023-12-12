#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll t;cin>>t;
	while(t--){
		ll n,a,k;cin>>n>>a>>k;
		ll net=(n-2)*180;
		ll num,den;
		num=n*(n-1)*a-2*a*(k-1)*n+2*net*(k-1);
		den=n*(n-1);
		ll g=__gcd(num,den);
		cout<<num/g<<' '<<den/g<<'\n';
	}
	return 0;
}
