#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<vector<int>> g(100000);
bool v[100000];
stack<int> a;
void dfs(int u){
	v[u]=1;
	a.push(u);
	for(auto i:g[u]){
		if(!v[i]){
			dfs(i);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int cnt=0;
	int x;cin>>x;
	x--;
	dfs(x);
	cout<<n-a.size()<<'\n';
}
