#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> v(1000,false);
vector<bool> r(1000,false);
int V=4;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool d(int i){
	v[i]=r[i]=true;
	for(auto it:adj[i]){
		if(!v[it]&& d(it))
			return true;
		if(r[it])
			return true;
	}
	r[i]=true;
	return false;
}
bool  isCyclic(){
	for(int i=0;i<V;i++){
		if(d(i))
			return true;
	}
	return false;
}
int main(){
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(2,0);
	addEdge(2,3);
	addEdge(3,3); 
    if(isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
	return 0;
}
