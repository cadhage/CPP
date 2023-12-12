#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int i);
		void addEdge(int a,int b);
		void DFS(int i);
		void DFS(int i,bool visited[]);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int a,int b){
	adj[a].push_back(b);
}
void Graph::DFS(int i){
	bool visited[V];
	DFS(i,visited);
}
void Graph::DFS(int i,bool visited[]){
	visited[i]=true;
	cout<<i<<" ";
	list<int>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			visited[*it]=true;
			DFS(*it,visited);
		}
	}
	
}
int main(){
	int q;cin>>q;
	
	while(q-->0){
		int n,m;cin>>n>>m;
		Graph g(n);
		while(m-->0){
			int a,b;cin>>a>>b;
			g.addEdge(a,b);
		}
		g.DFS(1);
	}
	return 0;
}
