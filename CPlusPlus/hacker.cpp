#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500];
void dfs_util(vector<int> adj[],int V,bool visited[],int i){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			visited[*it]=true;
			dfs_util(adj,V,visited,*it);	
		}
	}
}
void dfs(vector<int> adj[],int V){
	bool visited[V];
	cout<<"oollla"<<endl;
	for(int i=0;i<V;i++){
		dfs_util(adj,V,visited,i);
		cout<<endl;
	}
}
int main(){
	int n,u,v;cin>>n>>u>>v;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(adj,n+1);//	for(int i=0;i<=n;i++){
//		for(auto it=adj[i].begin();it!=adj[i].end();it++){
//			cout<<*it<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
