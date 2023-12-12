#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool DLS(int src, int target, int limit) 
{ 
    if (src == target) 
        return true; 
    if (limit <= 0) 
        return false; 
 	for (auto i = adj[src].begin(); i != adj[src].end(); ++i) 
       if (DLS(*i, target, limit-1) == true) 
          return true; 
  
     return false; 
}  
bool IDDFS(int src, int target, int max_depth) 
{ 
    for (int i = 0; i <= max_depth; i++) 
       if (DLS(src, target, i)) 
          return true; 
    return false; 
} 
int main() 
{ 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(2, 5); 
    addEdge(2, 6); 
    int target = 6, maxDepth = 3, src = 0; 
    if (IDDFS(src, target, maxDepth) == true) 
        cout << "Target is reachable from source "
                "within max depth"; 
    else
        cout << "Target is NOT reachable from source "
                "within max depth"; 
    return 0; 
}
