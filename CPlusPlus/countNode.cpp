#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void BFS(vector<int> adj[],int V,int i,int l){
	bool visited[V];
	fill(visited,visited+V,false);
	list<int> q;
	q.push_back(i);
	int level[V];
	level[i]=0;
	while(q.size()>0){
		i=q.front();
		//cout<<i<<" ";
		q.pop_front();
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			if(!visited[*it]){
				level[*it]=level[i]+1;
				visited[*it]=true;
				q.push_back(*it);
			}
		}
	}
	int count=0;
	for(int i=0;i<V;i++)
		cout<<i<<" "<<level[i]<<endl;
}
int main(){
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,1,5);
	addEdge(adj,2,6);
	BFS(adj,V,0,2);
	return 0;
}
