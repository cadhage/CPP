#include <bits/stdc++.h>
using namespace std;
#define V 5 
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
vector<int> adj1[1000];
void dfs(int i,vector<bool> &v,stack<int> &st){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it])
			dfs(it,v,st);
	}
	st.push(i);
}
void transpose(){
	for(int i=0;i<V;i++){
		for(auto it:adj[i]){
			adj1[it].push_back(i);
		}
	}
}
void dfsUtil(int i,vector<bool> &v){
	v[i]=true;
	cout<<i<<' ';
	for(auto it:adj1[i]){
		if(!v[it]){
			dfsUtil(it,v);
		}
	}
}
void printSCCs() 
{ 
	vector<bool> v(V,false);
	stack<int> st;
	for(int i=0;i<V;i++){
		if(!v[i])
			dfs(i,v,st);
	}
	transpose();
	for(auto i=0;i<V;i++)
		v[i]=false;
	while(!st.empty()){
		int it=st.top();
		st.pop();
		if(!v[it]){
			dfsUtil(it,v);
			cout<<'\n';
		}
	}
	
} 
int main() 
{ 
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    printSCCs(); 
    return 0; 
} 
