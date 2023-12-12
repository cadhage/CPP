#include <bits/stdc++.h>
using namespace std;
#define INF 999
#define V 9
int minDistance(vector<int> dist, vector<bool> sptSet) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
void dijkstra(int adj[][9],int i){
	vector<int> dist(9,INT_MAX);
	vector<bool> v(9,false);
	dist[i]=0;
	for(int u=0;u<8;u++){
		int i=minDistance(dist,v);
		v[i]=true;
		for(int j=0;j<9;j++){
			if(!v[j]&&adj[i][j] &&dist[i]!=INT_MAX
				&&dist[i]+adj[i][j]<dist[j])
				dist[j]=dist[i]+adj[i][j];
		}
	}
   for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 

}
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 
