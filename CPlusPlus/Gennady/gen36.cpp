#include <bits/stdc++.h>
using namespace std;
int  main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	long long md=1e9+7;
	#define ll long long
	while(tt--){
		int n;cin>>n;
		vector<long long> a(1<<n);
		vector<long long> good(1<<n);
		vector<long long> bad(1<<n);
		for(ll i=0;i<(1<<n);i++){
			cin>>a[i];
			bad[i]=i*a[i];
			good[i]=i*a[i];
			good[i]%=md;
			bad[i]%=md;
		}
		for(int i=0;i<(1<<n);i++){
			cout<<a[i]<<" "<<good[i]<<" "<<bad[i]<<"\n";
		}
		int q;cin>>q;
		while(q--){
			int i,k;cin>>i>>k;
			cout<<(k==1)?good[i]:bad[i]<<'\n';
		}
	}
	return 0;
}
