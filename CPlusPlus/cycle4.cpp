#include<bits/stdc++.h>
using namespace std;
bool DFSUtil(vector<int> v[],bool b[],bool f[],int c,int d);
bool DFS(int a[]){
	
	int n=sizeof(a)/sizeof(a[0]);
	vector<int> adj[n];
	for(int i=0;i<n;i++)
	{
			adj[i].push_back((i+a[i])%n);
	}
	int V=n;
	bool visited[V];
	bool rec[V];
	for(int i=0;i<V;i++){
	if (visited[i] == false) {
		if(DFSUtil(adj,visited,rec,i,V))
			//	cout<<"Yes"<<"\n";
				return true;
		}}
	return false;
}
bool DFSUtil(vector<int> adj[],bool visited[],bool rec[],int i,int V){
	if(!visited[i]){
		visited[i]=true;
		rec[i]=true;
		for(int x:adj[i]){
			if(!visited[x]&& DFSUtil(adj,visited,rec,x,V))
			return true;
			else if(rec[x])
				return true;
		}
		
	}
	
	rec[i]=false;
	return false;
}
int main(){
	int V=4;
	int arr[] = {2, -1, 1, 2, 2}; 
	if(DFS(arr))
	 cout<<"Yes";
	 else cout<<"no";
	return 0;
}
