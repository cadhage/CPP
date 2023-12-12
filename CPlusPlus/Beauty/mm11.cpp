#include <bits/stdc++.h>
using namespace std;
//static int V=0;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
void dfs(int V,int i,vector<bool> &v){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it])
			dfs(V,it,v);
	}
}
int motherVertices(int V){
	vector<bool> v(V,false);
	int res=0;
	for(int i=0;i<V;i++){
		if(!v[i]){
			dfs(V,i,v);
			res=i;
		}
	}
	fill(v.begin(),v.end(),false);
	dfs(V,res,v);
	for(int i=0;i<V;i++){
		if(!v[i])
			return -1;
	}
	return res;
}
int main(){
	int V=7;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,3);
	addEdge(4,1);
	addEdge(6,4);
	addEdge(5,6);
	addEdge(5,2);
	addEdge(6,0);
	cout<<motherVertices(V);
	return 0;
}
