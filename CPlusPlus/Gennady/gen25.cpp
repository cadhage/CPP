#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,p;cin>>n>>p;
		const int MAX=2010;
		vector<vector<int>> segs(MAX);
		for(int i=0;i<n;i++){
			int y,s,e;
			cin>>y>>s>>e;
			segs[y].push_back(e);
		}
		for(int y=0;y<MAX;y++){
			sort(segs[y].begin(),segs[y].end());
			
		}
		vector<int> dp(1,0);
		int ans=0;
		int cc=0;
		for(int y=0;y<MAX;y++){
			int ns=(int)segs[y].size();
			vector<int> new_dp(cc+1+ns,(int)2e9);
			for(int i=0;i<=cc;i++){
				for(int j=0;j<=ns;j++){
					new_dp[i+j]=min(new_dp[i+j],dp[i]+2*(j==0?0:segs[y][j-1]));
					if(dp[i]+y+(j==0?0:segs[y][j-1])<=p){
						ans=max(ans,i+j);
					}
				}
			}
			dp=new_dp;
			cc+=ns;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
