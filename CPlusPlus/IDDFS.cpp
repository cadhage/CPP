#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
bool DFSUtil(vector<int> adj[],int V,int src,int target,int limit){
	if(src==target)
	return true;
	if(limit<=0)
		return false;
	for(auto it=adj[src].begin();it!=adj[src].end();it++){
			if(DFSUtil(adj,V,*it,target,limit-1))
				return true;
		}
	return false;
}
bool IDDFS(vector<int> adj[],int V,int src,int target,int maxDepth){
	for(int i=0;i<=maxDepth;i++){
		if(DFSUtil(adj,V,src,target,i))
		return true;
	}
	return false;
}
int main(){
	int n = 7; 
    vector <int> edges[7]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 2); 
    addEdge(edges, 1, 3); 
    addEdge(edges, 1, 4); 
    addEdge(edges, 2, 5); 
    addEdge(edges, 2, 6); 
    int target = 6,maxDepth=3,src=0; 
	if(IDDFS(edges,n,src,target,maxDepth))
		cout << "Target is reachable from source "
                "within max depth"; 
    else cout<<"Not Reachble";
	return 0;
}
