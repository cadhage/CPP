#include <bits/stdc++.h>
using namespace std;
#define INF 9999
int minDistance(vector<int> dist, bool sptSet[],int V) 
{ 
   int min = INT_MAX, min_index; 
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
}
void dijkstra(int V,int src,int *graph){
    bool sptSet[V];
    vector<int> dist(V, INF); 
    dist[src] = 0; 
    for (int count = 0; count < V-1; count++) 
    { 
      int u = minDistance(dist, sptSet,V); 
      sptSet[u] = true; 
	   for (int v = 0; v < V; v++) 
         if (!sptSet[v] && *((graph+u*V)+v) && dist[u] != INT_MAX  
                                       && dist[u]+*((graph+u*V)+v)< dist[v]) 
            dist[v] = dist[u] + *((graph+u*V)+v); 
     } 
   
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
			printf("%d \t\t %d\n", i, dist[i]); 
}
int main() 
{ 
   int  V=9;
   int graph[][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(V,0,*graph);  
    return 0; 
} 
