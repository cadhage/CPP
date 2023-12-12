#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
	ld a,b,c;
	cin>>a>>b>>c;
	ld D=-(a+b)*b+a*c;
	ld Dx=-a*c*c;
	ld Dy=-(a+b)*a*c;
	ld d=Dx/D;
	ld g=Dy/D;
	ld e=(c+d)*g/(a+b+c+d);
	ld f=g-e;
	ld ans=a+b+c+d+e+f;
	ld p;cin>>p;
	cout<<fixed<<setprecision(2)<<ans*p<<"\n";
	}
	return 0;	
}
