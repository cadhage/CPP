#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> V(1000,false),R(1000,false);
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool isCyclic(int i,int n){
	V[i]=true;
	R[i]=true;
	for(auto it:adj[i]){
		if(!V[it] && isCyclic(it,n))
			return true;
		else if(R[i])
			return true;
	}
	return false;
}
bool isCyclic(int V){
	for(int i=0;i<V;i++){
		if(isCyclic(i,V))
			return true;
	}
	return false;
}
int main() 
{ 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3); 
    if(isCyclic(4)) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 
