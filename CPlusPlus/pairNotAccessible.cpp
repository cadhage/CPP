#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],bool visited[],int x,int k){
	for(auto it=adj[x].begin();it!=adj[x].end();it++){
		if(!visited[*it]){
		k++;
		visited[*it]=true;
		dfs(adj,visited,*it,k);
		}
	}
}
int countNonAccessible(vector<int> adj[],int n){
	bool visited[n*n+n];
//	memset(visited, false, sizeof(visited)); 
	int ans=0;
	for(int i=1;i<=n*n;i++){
		if(!visited[i]){
			visited[i]=true;
			int k=1;
			dfs(adj,visited,i,k);
			ans+=k*(n*n-k);
		}
	}
	return ans;
}
void insertPath(vector<int> graph[],int n,int x1,int y1,int x2,int y2){
	int a=(x1-1)*n+y1;
	int b=(x2-1)*n+y2;
	graph[a].push_back(b);
	graph[b].push_back(b);
}
int main(){
	int n=2;
	vector<int> graph[n*n+1];
	insertPath(graph,n,1,1,1,2);
	insertPath(graph,n,1,2,2,2);
	cout<<countNonAccessible(graph,n);
	return 0;
}
