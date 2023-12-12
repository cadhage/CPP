#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],v(1000,0),res,indegree(1000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
void topo(int n){
	bool flag=false;
	for(int i=0;i<n;i++){
		if(indegree[i]==0 && !v[i]){
			for(auto it:adj[i])
				indegree[it]--;
			v[i]=true;
			res.push_back(i);
			topo(n);
			res.pop_back();
			v[i]=false;
			for(auto it:adj[i])
				indegree[it]++;
			flag=true;
		}
	}
	if(!flag){
		for(auto it:res)
			cout<<it<<' ';
		cout<<'\n';
	}
}
int main(){
	addEdge(5,2);
	addEdge(5,0);
	addEdge(4,0);
	addEdge(4,1);
	addEdge(2,3);
	addEdge(3,1);
	topo(6);
	return 0;
}
