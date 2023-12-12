#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000],adjr[100000],v(100000,0),rec(100000,0),order,comp;
stack<int> st;
#define NIL -1
void dfs1(int i){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs1(it);
		}
	}
	order.push_back(i);
}
void dfs2(int i){
	v[i]=1;comp.push_back(i);
	for(auto it:adjr[i]){
		if(!v[it]){
			dfs2(it);
		}
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adjr[y].push_back(x);
	}
	for(int i=0;i<n;i++){
		if(!v[i])
			dfs1(i);
	}
	fill(v.begin(),v.end(),0);
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		int t=order[n-i-1];
		if(!v[t]){
			dfs2(t);
			if(comp.size()>1){
				for(auto it:comp){
					ans[it]=1;
				}
			}
			comp.clear();
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
