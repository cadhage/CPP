#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,g;cin>>n>>m>>g;
	vector<int> t(n);
	for(int i=0;i<n;i++)
		cin>>t[i];
	sort(t.begin(),t.end());
	int mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,t[i+1]-t[i]);
	}
	int ans=0;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(x<=mx)
			ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
