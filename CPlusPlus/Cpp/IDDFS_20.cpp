#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
}
bool dls(int s,int t,int limit){
	if(s==t)
		return true;
	if(limit<=0)
		return false;
	for(auto it:adj[s]){
		if(dls(it,t,limit-1)){
			return true;
		}
	}
	return false;
} 
bool IDDFS(int s,int t,int max_depth){
	for(int i=0;i<=max_depth;i++){
		if(dls(s,t,i)){
			return true;
		}
	}
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
