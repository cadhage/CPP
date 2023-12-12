#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define iPair pair<int,int>
void shortestPath(list<pair<int,int>> adj[],int V,int src) {
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop();
        for (auto i:adj[u]) 
        {  
            int v = (i).first; 
            int weight = (i).second;  
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
int main(){
	list<pair<int,int>> adj[9];
	adj[0].push_back(make_pair(1,4));
	adj[0].push_back(make_pair(7,8));
	adj[1].push_back(make_pair(2,8));
	adj[1].push_back(make_pair(7,11));
	adj[2].push_back(make_pair(3,7));
	adj[2].push_back(make_pair(8,2));
	adj[2].push_back(make_pair(5,4));
	adj[3].push_back(make_pair(4,9));
	adj[3].push_back(make_pair(5,9));
	adj[4].push_back(make_pair(5,10));
	adj[5].push_back(make_pair(6,2));
	adj[6].push_back(make_pair(7,1));
	adj[6].push_back(make_pair(8,6));
	adj[7].push_back(make_pair(8,7));
	shortestPath(adj,9,0);
	return 0;
}
