#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=7;
vector<bool> visited;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
void dfs(int i){
	visited[i]=true;
	for(auto it:adj[i]){
		if(!visited[it])
			dfs(it);
	}
}
void findMother(){
	int v=0;
	for(int i=0;i<V;i++){
		if(!visited[i]){
			dfs(i);
			v=i;
		}
	}
	fill(visited.begin(),visited.end(),false);
	dfs(v);
	for(int i=0;i<V;i++){
		if(!visited[i])
			return -1;
	}
	return v;
}
int main(){
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(4, 1); 
    addEdge(6, 4); 
    addEdge(5, 6); 
    addEdge(5, 2); 
    addEdge(6, 0); 
    cout << "A mother vertex is " << findMother(); 
	return 0;
}
