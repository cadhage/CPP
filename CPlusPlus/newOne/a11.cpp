#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int> V(1000,0);//,R(1000,false);
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool isCyclic(int i,int n){
	V[i]=1;
	for(auto it:adj[i]){
		if(V[i]==1)
			return true;
		if(V[it]==0 && isCyclic(it,n))
			return true;
	}
	V[i]=2;
	return false;
}
bool isCyclic(int n){
	for(int i=0;i<n;i++){
		if(V[i]==0)
		if(isCyclic(i,n))
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
