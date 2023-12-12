#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> v(1000,false);
vector<bool> r(1000,false);
int V=4;
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
bool d(int i,int parent){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it]&& d(it,i))
			return true;
		else if(it!=parent)
			return true;
	}
	return false;
}
bool isCyclic(){
	for(int i=0;i<V;i++){
		if(!v[i])
			if(d(i,-1))
			return true;
	}
	return false;
}
int main(){
	addEdge(1,0);
	addEdge(0,2);
	addEdge(2,1);
	addEdge(0,3);
	addEdge(3,4);
    if(isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
	return 0;
}
