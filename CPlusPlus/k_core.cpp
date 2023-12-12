#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void DFSUtil(vector<int> adj[],bool visited[],int V,int vDegree,int i,int k){
	visited[i]=true;
//	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])
			DFSUtil(adj,visited,V,vDegree,*it,k);
		}
}
int DFS(vector<int> adj[],int V,int k){
	bool visited[V];
	int start;
	fill(visited,visited+V,false);
	bool processed[V];
	fill(visited,visited+V,false);
	vector<int> vDegree(V);
	int mindeg=INT_MAX;
	for(int i=0;i<V;i++){
		vDegree[i]=adj[i].size();
		if(vDegree[i]<mindeg){
			mindeg=vDegree[i];
			start=i;
		}
	}
	DFSUtil(adj,visited,V,vDegree,start,k);
	for (int i=0; i<V; i++) 
        if (visited[i] == false) 
            DFSUtil(adj, visited,V, vDegree,i, k); 
    cout<<"k_kore"<<endl;
    for(int v=0;v<V;v++){
    	if(vDegree[v]>=k){
    		cout<<"\n["<<v<<"]";
    		for(auto it=adj[v].begin();it!=adj[v].end();it++)
    			if(vDegree[*it]>=k)
    			cout<<"->"<<*it;
		}
	}
}
int main(){
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,1,5);
	addEdge(adj,2,3);
	addEdge(adj,2,5);
	addEdge(adj,3,6);
	addEdge(adj,3,6);
	addEdge(adj,3,7);
	addEdge(adj,4,6);
	addEdge(adj,4,7);
	addEdge(adj,5,6);
	addEdge(adj,5,8);
	addEdge(adj,6,7);
	addEdge(adj,6,8);
	cout<<DFS(adj,V,3)<<" ";
	return 0;
}
