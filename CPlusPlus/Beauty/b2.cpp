#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=4;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
vector<bool> visited(100000,false);
void countPathsUtil(int u, int d,int &pathCount) 
{ 
    visited[u] = true; 
    if (u == d) 
        pathCount++; 
    else
    { 
        for (auto it : adj[u]) 
            if (!visited[it]) 
                countPathsUtil(it, d,pathCount); 
    } 
  
    visited[u] = false; 
}
int countPaths(int s, int d) 
{ 
    int pathCount = 0; 
    countPathsUtil(s, d,pathCount); 
    return pathCount; 
}  
int main(){
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(0, 3); 
    addEdge(2, 0); 
    addEdge(2, 1); 
    addEdge(1, 3);  
    int s=2,d=3;
    cout << "A mother vertex is " << countPaths(s,d); 
	return 0;
}
