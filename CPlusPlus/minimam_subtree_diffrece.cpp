#include<bits/stdc++.h>
using namespace std;
void dfs(int u,int parent,int total,vector<int> adj[],int subtree[],int &res){
	int sum=subtree[u];
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		int v=*it;
		if(v!=parent){
			dfs(v,u,total,adj,subtree,res);
			sum+=subtree[v];
		}
	}
	subtree[u]=sum;
	if(u!=0 && abs(total-2*sum)<res)
		res=abs(total-sum*2);
}
int getMinSubtreeSumDifference(int vertex[],int edges[][2],int N){
	int total_sum=0;
	int subtree[N];
	for(int i=0;i<N;i++){
		subtree[i]=vertex[i];
		total_sum+=vertex[i];
	}
	vector<int> adj[N];
	for(int i=0;i<N-1;i++){
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	int res=INT_MAX;
	dfs(0,-1,total_sum,adj,subtree,res);
	return res;
}
int main(){
	int vertex[]={4, 2, 1, 6, 3, 5, 2}; 
	 int edges[][2] = {{0, 1}, {0, 2}, {0, 3}, 
                      {2, 4}, {2, 5}, {3, 6}}; 
    int N = sizeof(vertex) / sizeof(vertex[0]); 
    cout << getMinSubtreeSumDifference(vertex, edges, N); 
	return 0;
}
