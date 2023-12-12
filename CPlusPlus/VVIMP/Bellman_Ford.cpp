#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define iPair pair<int,int>
void shortestPath(list<pair<int,int>> adj[],int V,int src) {
	list< iPair> pq;
    vector<int> dist(V, INF);  
    pq.push_back(make_pair(0, src)); 
    dist[src] = 0; 
    while (!pq.empty()) 
    {
        int u = pq.front().second; 
        pq.pop_front();
        for (auto i:adj[u]) 
        {  
            int v = (i).first; 
            int weight = (i).second;  
            if (dist[u] != INT_MAX &&dist[v] > dist[u] + weight) 
            {  
                dist[v] = dist[u] + weight; 
                pq.push_back(make_pair(dist[v], v)); 
            } 
        } 
    } 
    for(auto i:adj[src]) 
    {  
        int v = (i).first; 
        int weight = (i).second;  
        if (dist[src] != INT_MAX &&dist[v] > dist[src] + weight) 
		{  
            cout<<"Graph Has Negative Weight"<<endl;
            return;
        } 
    } 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        if(dist[i]!=INF)
			printf("%d \t\t %d\n", i, dist[i]); 
}
int main(){
	list<pair<int,int>> adj[9];
	adj[0].push_back(make_pair(1,-1));
	adj[0].push_back(make_pair(2,4));
	adj[1].push_back(make_pair(2,3));
	adj[1].push_back(make_pair(3,2));
	adj[1].push_back(make_pair(4,2));
	adj[3].push_back(make_pair(2,5));
	adj[3].push_back(make_pair(1,1));
	adj[4].push_back(make_pair(3,-3));
	shortestPath(adj,9,0);
	return 0;
}
