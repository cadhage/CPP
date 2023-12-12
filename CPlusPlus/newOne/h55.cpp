#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll r,c;cin>>r>>c;
		ll ri[r];
		ll ci[c];
		ll sumr=0;
		ll sumc=0;
		for(ll i=0;i<r;i++){
			cin>>ri[i];
		}
		for(ll i=0;i<c;i++){
			cin>>ci[i];
		}
		sort(ri,ri+r,[&](auto x,auto y){
			return x>y;
		});
		sort(ci,ci+c,[&](auto x,auto y){
			return x>y;
		});
		int cnt=0;
		for(int i=0;i<c;i++){
			if(ri[i]<=ci[i])
				cnt++;
		}
		//cout<<cnt<<'\n';
		if(cnt==c)
			cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}	
	return 0;
}

