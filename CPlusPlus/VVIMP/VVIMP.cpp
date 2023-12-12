#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
//void kruskal(vector<pair<int,int>> adj[],V)
//}
void addEdges(vector<pair<int,int>> adj[],int u,int v,int weight){
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}
void shortest_path(int src,vector<pair<int,int>> adj[],int V){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    vector<int> dist(V, INF); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop();  
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        {  
            int v = (*i).first; 
            int weight = (*i).second; 
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
}
void printGraph(vector<pair<int,int>> adj[],int V){
	int v,w;
	for(int i=0;i<V;i++){
		for(auto it=adj[i].begin();it<adj[i].end();it++){
			v=it->first;
			w=it->second;
			cout<<v<<" "<<w<<endl;
		}
		cout<<endl;
	}
}
void prims(vector<pair<int,int>> adj[],int V){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source 
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;  // Include vertex in MST 
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
}
int main(){
	int V=9;
	vector<pair<int ,int>> adj[V];
	addEdges(adj,0,1,4);
	addEdges(adj,0,7,8);
	addEdges(adj,1,2,8);
	addEdges(adj,1,7,11);
	addEdges(adj,2,3,7);
	addEdges(adj,2,8,2);
	addEdges(adj,2,5,4);
	addEdges(adj,3,4,9);
	addEdges(adj,3,5,14);
	addEdges(adj,4,5,10);
	addEdges(adj,5,6,10);
	addEdges(adj,6,8,6);
	addEdges(adj,6,8,7);
	addEdges(adj,7,8,7);
	shortest_path(0,adj,V);
	cout<<endl;
	prims(adj,V);
	return 0;
}
