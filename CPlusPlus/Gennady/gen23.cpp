#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,m;
		cin>>n>>m;
		vector<vector<pair<int,int>>> g(n);
		for(int i=0;i<m;i++){
			int x,y,z;cin>>x>>y>>z;
			x--,y--;
			g[x].emplace_back(y,z);
		}	
		const long long inf=(long long)1e18;
		vector<int> is_inf(n,3);
		{
			vector<long long> d(n,0);
			vector<int> last_update(n,-1);
			for(int it=0;it<2*n;it++){
				for(int i=0;i<n;i++){
					for(auto &p:g[i]){
						int to=p.first;
						int cost=p.second;
						if(d[i]+cost<d[to]){
							d[to]=d[i]+cost;
							last_update[to]=it;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				if(last_update[i]<n){
					is_inf[i]=0;
				}
			}
		}
		{
			vector<long long> d(n,0);
			vector<int> last_update(n,-1);
			for(int it=0;it<2*n;it++){
				for(int i=0;i<n;i++){
					for( auto &p:g[i]){
						int to=p.first;
						int cost=p.second;
						if(d[to]+cost<d[i]){
							d[i]=d[to]+cost;
							last_update[i]=it;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				if(last_update[i]<n){
					is_inf[i]=0;
				}
			}
		}
		vector<int> real_inf=is_inf;
		{
			for(int it=0;it<n;it++){
				for(int i=0;i<n;i++){
					for(auto &p:g[i]){
						int to=p.first;
						if(is_inf[i]&1){
							is_inf[to]|=1;
						}
						if(is_inf[to]&2){
							is_inf[i]|=2;
						}
					}
				}
			}
		}
		vector<vector<long long>> dist(n);
		for(int st=0;st<n;st++){
			vector<long long> d(n,inf);
			if(!real_inf[st]){
				d[st]=0;
				vector<int> que(1,st);
				vector<int> inq(n,0);
				inq[st]=1;
				for(int b=0;b<(int)que.size();b++){
					inq[que[b]]=0;
					for(auto &p:g[que[b]]){
						int to=p.first;
						if(real_inf[to])
							continue;
						int cost=p.second;
						if(d[que[b]]+cost<d[to]){
							d[to]=d[que[b]]+cost;
							if(!inq[to]){
								que.push_back(to);
								inq[to]=1;
							}
						}
					}
				}
			}
			dist[st]=d;
		}
		debug(dist);
		for(int i=0;i<n;i++){
			if(is_inf[i]){
					cout<<"INF"<<'\n';
					continue;
			}
			long long x=0;
			for(int j=0;j<n;j++){
			x=min(x,dist[j][i]);
			}
			long long y=0;
			for(int j=0;j<n;j++){	
				y=min(y,dist[i][j]);
			}
			long long z=x+y;
			assert(z>-inf);
			cout<<z<<'\n';
		}
	}	
	return 0;
}
