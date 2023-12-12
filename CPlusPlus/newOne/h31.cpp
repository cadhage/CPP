#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<vector<int>> g(1000);
bool v[1000];
void dfs(int u){
	v[u]=1;
	for(auto i:g[u]){
		if(!v[i]){
			dfs(i);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(!v[i]){
			cnt++;
			dfs(i);
		}
	}
	cout<<(cnt>k?-1:m-(n-k))<<'\n';
	return 0;
}
