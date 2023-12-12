#include <bits/stdc++.h>
using namespace std;
bitset<2010> g[2010],com;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin>>x;
			g[i][j]=x;
		}
	} 
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int cnt=0;
			cnt=(g[i]&g[j]).count();
			ans+=cnt*(cnt-1)/2;
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}
