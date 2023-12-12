#include <bits/stdc++.h>
using namespace std;
int V=5;
vector<int> adj[1000];
vector<bool> v(1000,false);
vector<bool> r(1000,false);
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
bool d(int i,int p){
	v[i]=true;
	for(auto it:adj[i])
	{
		if(!v[it]&&d(it,i))
			return true;
		if(it!=p){
			return true;
		}
	}
	return false;
}
bool isCyclic(){
	for(int i=0;i<V;i++){
		if(!v[i]){
			if(d(i,-1)){
				return true;
			}
		}
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
