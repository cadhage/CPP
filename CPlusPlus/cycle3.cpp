#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void printAdj(vector<int> adj[],int v){
	for(int i=0;i<v;i++){
		cout<<i<<" ";
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
bool DFSUtil(vector<int> v[],int c,int d,string dd[]);
void DFS(vector<int> adj[],int x,int V){
	string color[V];
	for(int i=0;i<V;i++){
		color[i]="white";
	}
	bool rec[V];
	for(int i=0;i<V;i++){
		if(color[i]=="white" && DFSUtil(adj,i,V,color))
				cout<<"Yes"<<"\n";
				return;
		}
	cout<<"No";
}
bool DFSUtil(vector<int> adj[],int i,int V,string color[]){
//	if(!visited[i]){
		color[i]="gray";
		for(int x:adj[i]){
			if(color[x]=="white"&& DFSUtil(adj,x,V,color))
				return true;
			else if(color[x]=="gray")
				return true;
		}
		color[i]="black";
//		return falsel
//	}
	
//	rec[i]=false;
	return false;
}
int main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,2,0);
	addEdge(adj,0,3);
	addEdge(adj,3,4);
	printAdj(adj,V);
	bool visited[V];
	DFS(adj,0,V);
	return 0;
}
