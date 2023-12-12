#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void dfs(int s,vector<bool> &v,int V){
	v[s]=true;
	for(auto it:adj[s]){
		if(!v[it])
			dfs(it,v,V);
	}
}
int count(int V){
	int res=0;
	vector<bool> v(V,false);
	for(int i=0;i<V;i++){
		if(!v[i]){
			dfs(i,v,V);
			res++;
		}
	}
	return res;
}
int main(){
	int V=5;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(3,4);
	cout<<count(V);
	return 0;
}
