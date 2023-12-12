#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
	//adj[b].push_back(a);
}
void transposeGraph(vector<int> adj[],vector<int> transpose[],int V)
{
	for(int i=0;i<V;i++){
		for(auto it:adj[i]){
			addEdge(transpose,it,i);
		}
	}
	
}
void displayGraph(vector<int> trans[],int V){
	for(int i=0;i<V;i++){
		for(auto it:trans[i]){
			cout<<it<<" ";
		}
		cout<<'\n';
	}
}
int main() 
{ 
    int v = 5; 
    vector<int> adj[v]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 3, 2); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 4, 3); 
    vector<int> transpose[v]; 
    displayGraph(adj, v); 
    cout<<"---------------------------------------\n";
    transposeGraph(adj, transpose, v); 
    displayGraph(transpose, v); 
    return 0; 
} 
