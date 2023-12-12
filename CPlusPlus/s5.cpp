#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
bool isCyclicUtil(int i,vector<bool> &v,vector<bool> &rec){
	rec[i]=v[i]=true;
	for(auto it: adj[i]){
		if(!v[it]&&isCyclicUtil(it,v,rec)){
			return true;
		}else if(rec[it])
			return true; 
	}
	rec[i]=false;
	return false;
}
bool isCyclic(){
	vector<bool> rec(V,false),v(V,false);
	for(int i=0;i<V;i++){
		if(!v[i]&&isCyclicUtil(i,v,rec))
			return true;
	}
	return false;
}
int main() 
{ 
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(2,0);
	addEdge(2,3);
	addEdge(3,3);
	isCyclic()?cout<<"Yes":"No";
    return 0; 
} 
