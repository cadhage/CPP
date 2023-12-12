#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}
printGraph(vector<int> adj[],int v){
	for(int i=0;i<v;i++){
		cout<<v<<" ";
		for(auto x:adj[i]){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	cout<<"_ _ _ _ _ _ _ _"<<"\n";
}
void BFS(int s,vector<int> adj[],int V) 
{ 
 	bool visited[V];
 	list<int> queue;
 	queue.push_back(s);
 	visited[s]=true;
 	while(queue.size()>0){
 		s=queue.front();
 		cout<<s<<" ";
 		queue.pop_front();
      	for(int n:adj[s]){
      		if(!visited[n]){
      			visited[n]=true;
      			queue.push_back(n);
			  }
		} 
    } 
} 
int main(){
	int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj,0 , 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2);  
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3);
	addEdge(adj,3,3) ;
    printGraph(adj, V);
	BFS(2,adj,V); 
	return 0;
}
