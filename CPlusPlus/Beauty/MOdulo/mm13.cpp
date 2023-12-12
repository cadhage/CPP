#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
int tc[1000][1000]={0};
void bfs(int i,int V){
	list<int> q;
	vector<int> level(V,0);
	vector<bool> v(V,false);
	q.push_back(i);
	v[i]=true;
	while(!q.empty()){		
		int i=q.front();
		cout<<i<<'\n';
		q.pop_front();
		for(auto it:adj[i]){
			if(!v[it])
			{
				level[it]=level[i]+1;
				v[it]=true;
				q.push_back(it);		
			}
		}
	}
	for(int it:level){
		cout<<it<<' ';
	}
}
int main(){
	int V=6;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	bfs(0,V);
	return 0;
}
