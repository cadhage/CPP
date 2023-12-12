#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
vector<int> v(10,0),level(10,-1);
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void dfs(int i){
	v[i]=1;
	cout<<i<<' ';
	for(auto it:adj[i]){
		if(!v[it]){
//			cout<<it<<' ';
			dfs(it);
		}
	}
}
void printGraph(){
	for(auto it:adj){
		if(it.size()>0){
		for(auto itr:it){
			cout<<itr<<' ';
		}
		cout<<'\n';}
	}
}
int main(){
	addEdge(0,1);
	addEdge(0,4);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(1,4);
	addEdge(2,3);
	addEdge(3,4);
//	printGraph();
	dfs(0);
	return 0;
}
