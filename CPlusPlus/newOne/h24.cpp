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
		ll n;cin>>n;
		vector<ll> a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end(),[&](auto a,auto b){
			return a>b;
		});
		set<ll> st;
		vector<bool> ar(n,false);
		int cnt=0;
		for(ll i=0;i<n-1;i++){
			for(ll j=i+1;j<n;j++){
				if(has_common(a[i],a[j])){
					cout<<"yes"<<a[i]<<' '<<a[j]<<'\n';
					ar[j]=true;
				}
				else {
					if(cnt==0){
						if(!ar[i])
							st.insert(a[i]);
						if(!ar[j])
							st.insert(a[j]);
						cout<<a[i]<<' '<<a[j]<<'\n';
						cnt++;
					}
					else {
						//ans+=a[j];
						if(!a[j])
							st.insert(a[j]);
						cnt++;
					}
					//cout<<a[i]<<' '<<a[j]<<'\n';
				}
			}
		}
		for(auto it:st){
			cout<<it<<' ';
		}
	}
	return 0;
}

