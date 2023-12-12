#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=6;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
vector<bool> visited(100000,false);
void bfs(int s,int l){
	vector<int> level(V,0);
	queue<int> q;
	visited[s]=true;
	q.push(s);
	level[s]=0;
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(auto it:adj[s]){
			if(!visited[it]){
				level[it]=level[s]+1;
				visited[it]=true;
				q.push(it);
			}
		}
	}
	int count=0;
	for(int i=0;i<V;i++){
		if(level[i]==l)
			count++;
	}
	cout<<count<<'\n';
}
int main(){
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1,3); 
    addEdge(2, 4);
	addEdge(2,5);
	int level=2;
	bfs(0,level);  
	return 0;
}
