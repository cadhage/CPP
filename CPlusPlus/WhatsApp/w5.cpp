#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
vector<bool> v(10000,0);
void dfs(vector<int> adj[],int x){
	v[x]=true;
	for(auto it:adj[x]){
		if(!v[it]){
			dfs(adj,it);
		}
	}
}
int coutTrees(vector<int> adj[],int V){
	int res=0;
	for(int i=0;i<V;i++){
		if(!v[i]){
			dfs(adj,i);
			res++;
		}
	}
	return res;
}
int main() 
{ 
    int n = 5; 
    vector <int> adj[n]; 
	addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 3, 4); 
    cout<<coutTrees(adj,n);
    return 0; 
} 
