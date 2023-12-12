#include <bits/stdc++.h>
using namespace std;
int dfs(vector<pair<int,int>> adj[],pair<int,int> disRev[],vector<bool> visit,int s){
	visit[s]=true;
	int totalRev=0;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i].first;
		if(!visit[v]){
			disRev[v].first=disRev[s].first+1;
			disRev[v].second=disRev[s].second;
			if(adj[s][i].second){
				disRev[v].second=disRev[s].second+1;
				totalRev++;
			}
			totalRev+=dfs(adj,disRev,visit,v);
		}
	}
	return totalRev;
}
void printMinEdgeReverseForRootNode(int edge[][2],int n){
	int V=n+1;
	vector<pair<int,int>> adj[V];
	pair<int,int> disRev[V];
	vector<bool> visit(V,false);
	int u,v;
	for(int i=0;i<n;i++){
		u=edge[i][0];
		v=edge[i][1];
		adj[u].push_back(make_pair(v,0));
		adj[v].push_back(make_pair(u,1));
	}
	for(int i=0;i<V;i++){
		visit[i]=false;
		disRev[i].first=disRev[i].second=0;
	}
	int root=0;
	int totalRev=dfs(adj,disRev,visit,root);
	for(int i=0;i<V;i++){
		cout<<i<<" : "<<disRev[i].first<<" "
		<<disRev[i].second<<'\n';
	}
	int res=INT_MAX;
	for(int i=0;i<V;i++){
		int edgesToRev=(totalRev-disRev[i].second)+
		(disRev[i].first-disRev[i].second);
		if(edgesToRev<res){
			res=edgesToRev;
			root=i;
		}
	}
	cout<<root<<" "<<res<<'\n';
}
int main() 
{ 
    int edges[][2] = 
    { 
        {0, 1}, 
        {2, 1}, 
        {3, 2}, 
        {3, 4}, 
        {5, 4}, 
        {5, 6}, 
        {7, 6} 
    }; 
    int e = sizeof(edges) / sizeof(edges[0]); 
  
    printMinEdgeReverseForRootNode(edges, e); 
    return 0; 
} 
