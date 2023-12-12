#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		vector<pair<string,bool>> a(n);
		map<string,array<int,2>> mp;
		for(int i=0;i<n;i++){
			string s;bool x;cin>>s>>x;
			mp[s][x]++;
			//mp.insert(s,mp[s]+1);
		}
		int ans=0;
		for(auto it:mp){
			ans+=max(it.second[0],it.second[1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
