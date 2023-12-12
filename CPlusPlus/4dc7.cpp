#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	//adj[y].push_back(x);
}
bool _dfs(int i,int t,int md){
	if(i==t)
		return true;
	if(md<=0)
		return false;
	for(auto it:adj[i]){
		if(_dfs(it,t,md-1)){
			return true;
		}
	}
	return false;
}
bool IDDFS(int src,int  target,int maxDepth){
	vector<bool> v(V,false);
	
	for(int i=0;i<=maxDepth;i++){
		if(_dfs(src,target,i))
			return true;
	}
	return false;
}
int main() 
{ 
    // Let us create a Directed graph with 7 nodes 
   // Graph g(7); 
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
