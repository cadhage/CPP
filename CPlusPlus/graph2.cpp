#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void DFS(int s);
		void DFS(int i,bool visited[]);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}
void Graph::DFS(int i){
	bool visited[V];
	list<int> q;
	visited[i]=true;
	DFS(i,visited);
}
void Graph::DFS(int i,bool visited[]){
	visited[i]=true;
	cout<<i+1<<" ";
	list<int>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			visited[*it]=true;	
		 DFS(*it,visited);
		 }
	}
}
int main() 
{ 
	// Create a graph given in the above diagram 
	int n,m;cin>>n>>m;
	Graph g(n); 
	int a=0,b=0;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g.addEdge(a-1, b-1); 
	}
//	g.addEdge(0, 1); 
//	g.addEdge(0, 2); 
//	g.addEdge(1, 2); 
//	g.addEdge(2, 0); 
//	g.addEdge(2, 3); 
//	g.addEdge(3, 3); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.DFS(0); 

	return 0; 
} 

