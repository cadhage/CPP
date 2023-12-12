#include <bits/stdc++.h>
using namespace std;
//static int V=0;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
int tc[1000][1000]={0};
void dfs(int V,int s,int vv,vector<bool> &v){
	tc[s][vv]=true;
	for(auto it:adj[vv]){
		if(!v[it])
			dfs(V,s,it,v);
	}
}
int motherVertices(int V){
	vector<bool> v(V,false);
	int res=0;
	for(int i=0;i<V;i++){
			dfs(V,i,i,v);
	}
	for(int i=0;i<V;i++){   
		for(int j=0;j<V;j++)
			cout<<tc[i][j]<<' ';
		cout<<'\n';
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
