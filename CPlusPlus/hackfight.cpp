// A C++ program for Bellman-Ford's single source 
// shortest path algorithm. 
#include <bits/stdc++.h> 
using namespace std;
struct Edge{
	int src,dest,weight;
};
struct Graph{
	int E,V;
	struct Edge* edge;
};
struct Graph* createGraph(int V,int E){
	struct Graph* graph=new Graph;
	graph->E=E;
	graph->V=V;
	graph->edge=new Edge[E];
	return graph;
}
// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < n; ++i) 
		cout<<i<<"\t"<<dist[i]<<"\n"; 
} 
void BellmanFord(struct Graph* graph, int src) 
{ 
	int V=graph->V;
	int E=graph->E;
	int dist[V];
	for(int i=0;i<V;i++)
		dist[i]=INT_MAX;
	dist[src]=0;
	for(int i=1;i<V;i++){
		for(int j=0;j<E;j++){
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
				dist[v]=dist[u]+weight;
		}
	}
	for(int i=0;i<E;i++){
			int u=graph->edge[i].src;
			int v=graph->edge[i].dest;
			int weight=graph->edge[i].weight;
			if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
				cout<<"-ve  Cycle"<<endl;
	}
	printArr(dist,V);
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph 
	int E = 8; // Number of edges in graph 
	struct Graph* graph = createGraph(V, E); 
//	int q;cin>>q;
//	while(q-->0){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,c;cin>>x>>y>>c;
		graph->edge[i].src = x; 
		graph->edge[i].dest = y; 
		graph->edge[i].weight = c; 
	}
//	int qq;cin>>qq;
		BellmanFord(graph, 4); 
//}
//	BellmanFord(graph, 0); 
	return 0; 
} 

