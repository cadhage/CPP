#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int> indegree(1000,0);
vector<vector<int>> sol;
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
void topologicalSort(int V){
	vector<int> in_degree(V,0);
	for(int i=0;i<V;i++){
		for(int it:adj[i])
			in_degree[it]++;
	}
	queue<int> q;
	for(int i=0;i<V;i++){
		if(in_degree[i]==0){
			q.push(i);
		}
	}
	int cnt=0;
	vector<int> top_order;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		top_order.push_back(u);
		for(auto it:adj[u]){
			if(--in_degree[it]==0){
				q.push(it);
			}
		}
		cnt++;
//		if(cnt!=V){
//			cout<<"Exist Cycle\n";
//			return;
//		}
		for(int i=0;i<top_order.size();i++){
			cout<<top_order[i]<<' ';
		}
		cout<<'\n';
	}
}
int main(){
	int V,m;cin>>V>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		addEdge(x,y);
	}
	topologicalSort(V);
	return 0;
}
