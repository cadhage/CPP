#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int V=4,E=4,n=4,m=4,NIL=0,INF=INT_MAX;
int pairU[1000]={0};
int pairV[1000]={0};
int dist[1000]={0};
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool bfs() 
{ 
    queue<int> Q;
    for (int u=1; u<=m; u++) 
    { 
        if (pairU[u]==0) 
        { 
            dist[u] = 0; 
            Q.push(u); 
        } 
        else dist[u] = INF; 
    } 
    dist[0] = INF;   
    while (!Q.empty()) 
    { 
        int u = Q.front(); 
        Q.pop(); 
        if (dist[u] < dist[0]) 
        { 
            for (auto i:adj[u]) 
            { 
                int v = i;   
                if (dist[pairV[v]] == INF) 
                { 
                    dist[pairV[v]] = dist[u] + 1; 
                    Q.push(pairV[v]); 
                } 
            } 
        } 
    } 
    return (dist[0] != INF); 
} 
  
bool dfs(int u){
	if(u!=0){
		for(auto i:adj[u]){
			int v=i;
			if(dist[pairV[v]]==dist[u]+1){
				if(dfs(pairV[v])){
					pairV[v]=u;
					pairU[u]=v;
					return true;
				}
			}
		}
		dist[u]=0;
		return false;
	}
	return true;
}
int hopcroftKarp(){
	int res=0;
	while(bfs()){
		for(int i=1;i<=m;i++){
			if(pairU[i]==0 && dfs(i))
				res++;
		}
	}
	return res;
}
int main(){
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(2, 1); 
    addEdge(3, 2); 
    addEdge(4, 2); 
    addEdge(4, 4); 
    cout << "Size of maximum matching is " <<hopcroftKarp(); 
	return 0;
}
