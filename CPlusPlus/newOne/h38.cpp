#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define iPair pair<int,int>
vector<pair<int,int>> adj[10000];
void shortestPath(int V,int src) {
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
	int n,m;cin>>n>>m;
	//vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		x--;y--;
		adj[x].push_back(make_pair(y,z));
	}
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	shortestPath(n,0);
	return 0;
}

