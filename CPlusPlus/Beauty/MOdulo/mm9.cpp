#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
vector<int> v(1000,0);
stack<int> s;
void dfs(int i){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs(it);
		}
	}
	s.push(i);
}
void topologicalSort(int n){
	for(int i=1;i<=n;i++){
		if(!v[i])
			dfs(i);
	}
	for(int i=0;i<n;i++){
		cout<<s.top()<<' ';
		s.pop();
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
	//	x--;y--;
		addEdge(x,y);
	}
  //  cout << "Following is a Topological Sort of the given graph \n"; 
    topologicalSort(n);
	return 0;
}
