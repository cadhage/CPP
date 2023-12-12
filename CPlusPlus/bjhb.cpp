#include <bits/stdc++.h>
using namespace std;
#define N 1000
int fruits[N];
int parent[N];
int dp[N][20];
vector<int> H[N];
void dfs1(vector<int> adj[],int s,int p,int h){
	parent[s]=p;
	H[h].push_back(s);
	for(auto it:adj[s]){
		if(it!=p)
			dfs1(adj,it,s,h+1);
	}
}
int dfs2(vector<int> adj[],int s,int p,int h,int j){
	int ans=0;
	if(dp[s][j])
		parent[s]=p;
	H[h].push_back(s);
	if(j>0){
	for(auto &it:H[h]){
		if(it!=p)
			dfs2(adj,it,parent[it],h,j-1);
	}
	}
	for(auto &i:adj[s]){
		if(i!=p){
			ans=max(ans,dfs2(adj,i,s,h+1,j));
		}
	}
	if(fruits[s]==1)
		ans++;
	return ans;
}
int maxFruit(vector<int> adj[],int f[],int n,int m,int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<20;j++){
			dp[i][j]=-1;
			fruits[i]=0;
		}
	}
	for(int i=0;i<m;i++){
		fruits[f[i]]=1;
	}	
	dfs1(adj,1,0,0);
	int ans=dfs2(adj,1,0,0,k);
	return ans;
}
void addEdge(vector<int> tree[], int u, int v) 
{ 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 
int main(){
	int n = 12; // Number of nodes 
    int k = 2; // Number of allowed jumps 
    vector<int> tree[N]; 
    addEdge(tree, 1, 2); 
    addEdge(tree, 1, 3); 
    addEdge(tree, 2, 4); 
    addEdge(tree, 2, 5); 
    addEdge(tree, 5, 9); 
    addEdge(tree, 9, 10); 
    addEdge(tree, 9, 11); 
    addEdge(tree, 11, 12); 
    addEdge(tree, 1, 3); 
    addEdge(tree, 3, 7); 
    addEdge(tree, 7, 6); 
    addEdge(tree, 7, 8); 
    int NodesWithFruits[] = { 2, 4, 5, 7, 8, 9, 11, 12 };  
    int m = sizeof(NodesWithFruits) / sizeof(NodesWithFruits[0]); 
    int ans = maxFruit(tree, NodesWithFruits, n, m, k); 
    cout << ans << endl; 
	return 0;
}
