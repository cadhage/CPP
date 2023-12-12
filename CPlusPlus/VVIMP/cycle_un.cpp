#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> V(1000,false),R(1000,false);
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
bool isCyclic(int i,int parent,int n){
	V[i]=true;
	for(auto it:adj[i]){
		if(!V[it])
		{
			if(isCyclic(it,i,n))
				return true;
		}
		else if(it!=parent)
			return true;
		}
	return false;
}
bool isCyclic(int n){
	for(int i=0;i<n;i++){
		if(!V[i])
		if(isCyclic(i,-1,n))
			return true;
	}
	return false;
}
int main() 
{ 
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 0); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    if(isCyclic(5)) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 
