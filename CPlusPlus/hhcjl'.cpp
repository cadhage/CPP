#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a,b,n;
ll f(int c){
	return 1LL * a * c * c + 1LL * b * (n - c) * (n - c);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;cin>>q;
	while(q-->0){
		//ll n,a,b;
		cin>>n>>a>>b;
		ll i=0,j=n,mn=INT_MAX;
		ll x = f(floor(b * n / (a + b))), y = f(floor(b * n / (a + b)) + 1);
		    cout << min(x,y) << "\n";
		cout<<mn<<endl;
	}
	return 0;
}
