#include<bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f 
#define V 5
vector<pair<int,int>> adj[10000];
char alph[]={'a','b','c','d','e'};
void printPath(vector<int> path,int j){
	if(path[j]==-1)
		return;
	printPath(path,path[j]);
	cout<<"-"<<alph[j];
}
void addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
} 
void shortestPath(int src) 
{ 
	list<pair<int,int>> pq; 
	vector<int> dist(V, INF);  
	pq.push_back(make_pair(0, src)); 
	vector<int> parent(V,-1);
	dist[src] = 0;
	parent[src]=-1; 
	int count=0;
	while (!pq.empty()) 
	{ 
		int u = pq.front().second; 
		pq.pop_front(); 
		for (auto i:adj[u]){
			int v = (i).first; 
			int weight = (i).second; 
			if (dist[v] > dist[u] + weight) 
			{ 
				dist[v] = dist[u] + weight; 
				parent[v]=u;
				pq.push_back(make_pair(dist[v], v)); 
				count++;
				if(count==V*V){
					cout<<"Negative Cycle detected"<<'\n';
					return;
				}
			} 
		} 
	}  
	for (int i = 0; i < V; i++) {
        cout<<i<<"\t"<<'a';
		printPath(parent,i);
		cout<<"\t\t"<<dist[i];
		cout<<'\n'; 
	}
} 
int main() 
{ 
	
	addEdge(0, 1, -20); 
	addEdge(1, 2, 10); 
	addEdge(2, 0, 5); 
	addEdge(2, 1, -15);  
	shortestPath(0); 

	return 0; 
} 

