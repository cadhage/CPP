#include <bits/stdc++.h>
using namespace std;
struct tri{
	int a,b,c;
};
vector<tri> adj[1000];
void addEdge(int src,int dest,int t,int h){
	adj[src].push_back({dest,t,h});
}

void DFS(vector<int> vi,int s){
	vi[s]++;
	cout<<s<<' ';
	for(auto it:adj[s]){
	if(vi[it.a]==0){
			DFS(vi,it.a);
	}
	if(vi[it.a]==1)
		cout<<"( "<<it.a<<" )"<<'\n';
	}
}
int main(){
	int V;cin>>V;
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int u,v,t,h;cin>>u>>v>>t>>h;
		u--;v--;
		addEdge(u,v,t,h);	
	}
	for(int i=0;i<V;i++){
		vector<int> vi(1000,0);
		DFS(vi,i);
		//vi.clear();
		cout<<'\n';
	}
	return 0;
}
