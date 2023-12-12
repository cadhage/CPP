#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void BFS(vector<int> adj[],int V,int i){
	bool visited[V];
	fill(visited,visited+V,false);
	visited[i]=true;
	list<int> q;
	q.push_back(i);
	while(q.size()>0){
		i=q.front();
		cout<<i<<" ";
		q.pop_front();
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			if(!visited[*it])
			{
				q.push_back(*it);
				visited[*it]=true;
			}
		}
	}
	
}
int main(){
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);
	BFS(adj,V,2);
	return 0;
}
