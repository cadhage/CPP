#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int buid_tree(int a[],int n){
	int root=0;
	for(int i=0;i<n;i++){
		if(a[i]==-1)
		root=i;
		else{
			adj[i].push_back(a[i]);
			adj[a[i]].push_back(i);
		}
	}
}
int BFS(int root,int V){
	map<int,int> vis;
	list<pair<int,int>> q;
	int max=0;
	q.push_back({start,0});
	pair<int,int> p;
	while(!q.size()){
		p=q.front();
		vis[p.first]=1;
		max=max(max,p.second);
		q.pop();
		for(auto it=adj[p.first].begin();it!=adj[p.second];it++){
			if(!vis[p.first][i])
			 q.push_back({adj[p.first][i]});
		}
		return max;
		
	} 
}
int main(){
	int a[]={-1,0,1,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	int root=buitd_tree(a);
	int ma=BFS(root,n);
	return 0;
}
