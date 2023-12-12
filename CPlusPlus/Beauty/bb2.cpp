#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
//stack<int> st;
void topoSort(int i,vector<bool> &v,vector<int> &dep,int &time,int V){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it]){
			topoSort(it,v,dep,time,V);
		}
	}
	dep[++time]=i;
}
void topo_Sort(int V){
	vector<bool> v(V,false);
	vector<int> dep(V,-1);
	int time=-1;
	for(int i=0;i<V;i++){
		if(!v[i])
			topoSort(i,v,dep,time,V);
	}
	for(int i=V-1;i>=0;i--){
		cout<<dep[i]<<' ';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V=6;
	addEdge(5,2);
	addEdge(5,0);
	addEdge(4,0);
	addEdge(4,1);
	addEdge(2,3);
	addEdge(3,1);
	topo_Sort(V);
	return 0;
}
