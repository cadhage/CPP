#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		long double a,b,c;
		cin>>a>>b>>c;
		long double D=-(a+b)*b+a*c;
		long double Dx=-a*c*c;
		long double Dy=-(a+b)*a*c;
		long double d=Dx/D;
		long double g=Dy/D;
		long double e=(c+d)*g/(a+b+c+d);
		long double f=g-e;
		long double ans=a+b+c+d+e+f;
		long double temp;cin>>temp;
		cout<<fixed<<setprecision(2)<<ans*temp<<'\n';
	}
	return 0;
}
