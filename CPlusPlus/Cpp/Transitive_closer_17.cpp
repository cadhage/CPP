#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
const int MAX=100;
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
}
void dfs(int i,int j,bool tc[][MAX]){
	tc[i][j]=1;
	for(auto it:adj[j]){
		if(!tc[i][it]){
			dfs(i,it,tc);
		}
	}
}
void solver(int n){
	int last=0;
	bool tc[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tc[i][j]=0;
		}
		//cout<<'\n';
	}
	for(int i=0;i<n;i++)
		//if(!v[i]){
			dfs(i,i,tc);	
	//	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<tc[i][j]<<' ';
		}
		cout<<'\n';
	}
}
int main() 
{ 
  // Graph g(7); 
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3); 
    solver(4);
    return 0; 
}
