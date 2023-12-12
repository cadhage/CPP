#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void dfs(int i,vector<bool> &v){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs(it,v);
		}
	}
}
int countTrees(){
	int sum=0;
	vector<bool> v(V,false);
	for(int i=0;i<V;i++){
		if(!v[i])
		{
			dfs(i,v);
			sum++;
		}
	}
	return sum;
}
int main() 
{ 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(3, 4); 
    cout << countTrees(); 
    return 0; 
} 

