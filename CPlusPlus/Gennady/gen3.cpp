#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		b+=c;
		long long g=__gcd(a,c);
		a/=g;
		c/=g;
		g=__gcd(b,c);
		b/=g;
		c/=g;
		g=__gcd(d,c);
		d/=g;
		c/=g;
		assert(c==1);
		cout<<a*b*d<<'\n';
	}
	return 0;
}
