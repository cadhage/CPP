#include <bits/stdc++.h>
using namespace std;
#define V 5
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
int ct[2]={0};
void _dfs(int i,vector<bool> &v){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it])
			_dfs(it,v);
	}

}
void DFS(int n,int k){
	vector<bool> v(n,false);
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		a[i]=i%k;
	for(int i=0;i<n/2;i++){
		adj[a[i]].push_back(a[n-i-1]);
		adj[a[n-1-i]].push_back(a[i]);
	}
	_dfs(0,v);
	for(int i=0;i<n;i++)
		cout<<v[a[i]];
}
int main() 
{ 
    DFS(10,3); 
  
    return 0; 
} 
