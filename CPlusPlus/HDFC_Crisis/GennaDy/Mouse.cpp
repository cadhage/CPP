#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,m,k;
		cin>>n>>m>>k;
		map<int,vector<pair<int,int>>> mp;
		for(int i=0;i<k;i++){
			int x,y,z;
			cin>>x>>y>>z;
			mp[x].emplace_back(y,z);
		}
		const long long inf=(long long) 1e18;
		vector<long long> ans(k+1,inf);
		vector<vector<long long>> dp(k+1,vector<long long>(2,inf));
		dp[0][0]=0;
		int last_row=1;
		int cc=0;
		for(auto &vv:mp){
			auto &v=vv.second;
			sort(v.begin(),v.end());
			for(int i=0;i<=cc;i++){
				for(int j=0;j<2;j++){
					dp[i][j]+=vv.first-last_row;
				}
			}
			last_row=vv.first;
			int sz=(int)v.size();
			vector<long long> ddp(k + 1);
	        vector<long long> udp(k + 1);
		    for (int j = 0; j <= k; j++) {
		        ddp[j] = dp[j][0];
		        udp[j] = dp[j][1];
		    }
		    for (int j = 0; j < sz; j++) {
		        for (int u = cc + j; u >= 0; u--) {
		           ddp[u + 1] = min(ddp[u + 1], ddp[u] + v[j].second);
		        }
		    	for (int u = 0; u <= cc + j + 1; u++) {
		        	ans[u] = min(ans[u], ddp[u] + v[j].first - 1);
		            dp[u][0] = min(dp[u][0], ddp[u] + 2 * (v[j].first - 1));
		            dp[u][1] = min(dp[u][1], ddp[u] + m - 1);
		        }
		    }
	        for (int j = 0; j < sz; j++) {
	          for (int u = cc + j; u >= 0; u--) {
	            udp[u + 1] = min(udp[u + 1], udp[u] + v[sz - 1 - j].second);
	          }
	          for (int u = 0; u <= cc + j + 1; u++) {
	            ans[u] = min(ans[u], udp[u] + m - v[sz - 1 - j].first);
	            dp[u][1] = min(dp[u][1], udp[u] + 2 * (m - v[sz - 1 - j].first));
	            dp[u][0] = min(dp[u][0], udp[u] + m - 1);
	          }
	        }
			cc+=sz;
		}
		for (int i = 1; i <= k; i++) {
      		if (i > 1) {
      		  cout << " ";
      	}
     	cout << ans[i];
    }
    cout << '\n';
	}
	return 0;
}
