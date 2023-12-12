#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
}
bool isCyclicUtil(int i){
	v[i]=1;
	for(auto it:adj[i]){
		if(v[i]==0 && isCyclicUtil(it)){
			return true;
		}
		else if(v[it]==1)
			return true;
	}
	v[i]=2;
	return false;
} 
bool isCyclic(int n){
	for(int i=0;i<n;i++)
		if(v[i]==0 && isCyclicUtil(i))
			return true;
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
