#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<ll> a(n);
		ll xr=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			xr^=a[i];
		}
		cout<<xr<<' '<<'\n';
//		for(int i=0;i<n;i++){
//			x^=()
//		}
	}
	return 0;
}
