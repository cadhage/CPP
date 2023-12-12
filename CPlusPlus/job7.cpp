#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define V 6
vector<int> adj[10000];
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void APUtil(int u,vector<bool> &v,vector<int> &disc,  
                                      vector<int> &low,vector<int> &parent, vector<bool> &ap,int time) 
{  
    int child= 0; 
    v[u] = true; 
    disc[u] = low[u] = ++time; 
    for (auto it: adj[u]) 
    {  
        if (!v[it]) 
        { 
            child++; 
            parent[it] = u; 
            APUtil(it, v, disc, low, parent, ap,time); 
            low[u]  = min(low[u], low[it]); 
			if (parent[u] == NIL && child > 1) 
               ap[u] = true; 
            if (parent[u] != NIL && low[it] >= disc[u]) 
               ap[u] = true; 
        } 
        else if (it != parent[u]) 
            low[u]  = min(low[u], disc[it]); 
    } 
}   
void AP() 
{ 
  	vector<int> disc(V,0),low(V,0),parent(V,NIL);
  	vector<bool> v(V,false),AP(V,false); 
    for (int i = 0; i < V; i++) 
        if (v[i] == false) 
            APUtil(i, v, disc, low, parent, AP,0); 
    for (int i = 0; i < V; i++) 
        if (AP[i]) 
            cout << i << " "; 
} 
 
int main() 
{  
    addEdge(0, 1); 
    addEdge(1, 2); 
    addEdge(2, 3);
   	AP(); 
  
    return 0; 
} 
