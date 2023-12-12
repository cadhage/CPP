#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=6;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
vector<bool> visited(100000,false);
void bfs(int s){
	queue<int> q;
	visited[s]=true;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		cout<<s<<" ";
		for(auto it:adj[s]){
			if(!visited[it]){
				q.push(it);
				visited[it]=true;
			}
		}
	}
}
int main(){
 	int n,e;
 	cin>>n>>e;
 	int a,b;
 	for(int i=0;i<e;i++){
 		cin>>a>>b;
 		addEdge(a,b);
	 }
	 for(int i=0;i<n;i++){
	 	if(!visited[i])
	 		bfs(i);
	 }
	return 0;
}
