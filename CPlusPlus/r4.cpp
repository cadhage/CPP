#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],v(1000,0),res,indegree(1000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
void topo(int i,int n){
	v[i]=true;
	for(auto it:adj[i])
		if(!v[it])
			topo(it,n);
	res.push_back(i);
}
void topo_solver(int n){
	for(int i=0;i<n;i++){
		if(!v[i])
			topo(i,n);
	}
	for(auto it:res){
		cout<<it<<'\n';
	}
	for(int i=0;i<res.size();i++){
		int t=res[i];
		for(auto it:adj[i]){
			v[it]=true;
		}
		for(int j=i+1;j<res.size();j++){
			if(!v[res[j]]){
				cout<<t<<"-"<<res[j]<<'\n';
			}
			v[res[j]]=false;
		}
	}
}
int main(){
	addEdge(5,2);
	addEdge(5,0);
	addEdge(4,0);
	addEdge(4,1);
	addEdge(2,3);
	addEdge(3,1);
	topo_solver(6);
	return 0;
}
