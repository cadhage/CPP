#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
bool has_common(ll a,ll b){
	vector<int> ar;
	while(a){
		ar.push_back(a%10);
		a/=10;
	}
	while(b){
		ll x=b%10;
		for(ll i=0;i<ar.size();i++){
			if(ar[i]==x){
				return true;
			}
		}
		b/=10;
	}
	return false;
}
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
		int a[r][c];
		int mx=max(r,c);
		int mn=min(r,c);
		for(int i=0;i<mx;i++){
			for(int j=0;j<mx;j++){
				a[i][j]=0;
			}
		}
		for(int i=0;i<r;i++){
			int n=ri[i]-1;
			for(int j=0;j<c;j++){
				if(n>=0)
					a[i][n]=1;
				n--;	
			}
		}
		int cnt=0;
		int v[r];
		for(int i=0;i<r;i++){
			int sum=0;
			for(int j=0;j<c;j++){
				//cout<<a[i][j]<<' ';
				sum+=a[i][j];
			}
			v[i]=sum;
		}
		for(int i=0;i<mn;i++){
			if(v[i]==ci[i]){
				cnt++;
			}
		}
		if(cnt==c)
			cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}

