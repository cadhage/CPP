#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
}
void DFSUtil(vector<int> v[],bool visited[],stack<int> &st,int c,int d);
void DFS(vector<int> adj[],int i,int V){
	bool visited[V];
	stack<int> st;
	for(int i=0;i<V;i++)
		if(!visited[i])
		DFSUtil(adj,visited,st,i,V);
	 while (!st.empty()) 
    { 
        cout << st.top()<< " "; 
        st.pop(); 
    } 
}
void DFSUtil(vector<int> adj[],bool visited[],stack<int> &Stack,int v,int V){
visited[v] = true; 
    for (int i:adj[v]) 
        if (!visited[i]) 
            DFSUtil(adj, visited, Stack,i,V); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
}
int main(){
	int V=6;
	vector<int> adj[6];
	addEdge(adj,5,2);
	addEdge(adj,5,0);
	addEdge(adj,4,0);
	addEdge(adj,4,1);
	addEdge(adj,2,3);
	addEdge(adj,3,1);
	//printAdj(adj,V);
	bool visited[V];
	DFS(adj,0,V);
	return 0;
}
