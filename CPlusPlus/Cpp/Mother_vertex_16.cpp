#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
}
void dfs(int i){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs(it);
		}
	}
}
void solver(int n){
	int last=0;
	for(int i=0;i<n;i++)
		if(!v[i]){
			dfs(i);
			last=i;	
		}
	fill(v.begin(),v.end(),0);
	dfs(last);
	for(int i=0;i<n;i++){
		if(!v[i]){
			cout<<-1<<'\n';
			return;
		}
	}
	cout<<last<<'\n';
}
int main() 
{ 
  // Graph g(7); 
  addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(4, 1); 
    addEdge(6, 4); 
    addEdge(5, 6); 
    addEdge(5, 2); 
    addEdge(6, 0);
    solver(7);
    return 0; 
}
