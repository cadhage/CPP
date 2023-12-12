#include <bits/stdc++.h>
using namespace std;
//static int V=0;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
int tc[1000][1000]={0};
void dfs(int s,int d,int &count,vector<bool> &v,int V){
	v[s]=true;
	if(s==d)
		count++;
	else{
		for(auto it:adj[s]){
			if(!v[it])
				dfs(it,d,count,v,V);
		}
	}
	v[s]=false;
}
int countPaths(int s,int d,int V){
	vector<bool> v(V,false);
	int res=0;
	int pathCount=0;
	dfs(s,d,pathCount,v,V);
	return pathCount;
}
int main(){
	int V=4;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(2,0);
	addEdge(2,1);
	addEdge(1,3);
	cout<<countPaths(2,3,V);
	return 0;
}
