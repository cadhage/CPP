#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
void addEdges(vector<pair<int,int>> adj[],int u,int v,int weight){
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}
void prims(vector<pair<int,int>> adj[],int V){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int src=0;
	vector<int> key(V,INF),parent(V,INF);
	vector<bool> inMST(V,false);
	pq.push(make_pair(0,src));
	key[src]=0;
	while(!q.empty()){
		int u = pq.top().second; 
        pq.pop(); 
  		in
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
	prims(adj,V);
	return 0;
}
