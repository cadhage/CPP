#include <bits/stdc++.h>
using namespace std;
void dfs(int u,int parent,int totalSum,vector<int> edge[],int subtree[],int &res){
	int sum=subtree[u];
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(v!=parent){
			dfs(v,u,totalSum,edge,subtree,res);
			sum+=subtree[v];
		}
	}
	subtree[u]=sum;
	if(u!=0 && abs(totalSum-2*sum)<res)
		res=abs(totalSum-2*sum);
}
int getMinSumTreeDiffrence(int vertex[],int edge[][2],int n){
	int totalSum=0;
	int subtree[n];
	for(int i=0;i<n;i++){
		subtree[i]=vertex[i];
		totalSum+=vertex[i];
	}
	vector<int> adj[n];
	for(int i=0;i<n-1;i++){
		adj[edge[i][0]].push_back(edge[i][1]);
		adj[edge[i][1]].push_back(edge[i][0]);
	}
	int res=INT_MAX;
	dfs(0,-1,totalSum,adj,subtree,res);
	return res;
}
int main() 
{ 
	int vertex[]={4,2,1,6,3,5,2};
	int edge[][2]={{0,1},{0,2},{0,3},{2,4},{2,5},{3,6}};
	int n=sizeof(vertex)/sizeof(vertex[0]);
	cout<<getMinSumTreeDiffrence(vertex,edge,n);
    return 0; 
} 
