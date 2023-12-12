#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=5;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
vector<bool> visited(100000,false);
void dfs(int s){
	stack<int> st;
	st.push(s);
	while(!st.empty()){
		s=st.top();
		st.pop();
		if(!visited[s]){
			cout<<s<<" ";
			visited[s]=true;	
		}
		for(auto it:adj[s]){
			if(!visited[it]){
				st.push(it);
			}
		}
	}
}
int main(){
	addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3);
	addEdge(1,4);  
    for(int i=0;i<V;i++)
    	if(!visited[i])
    		dfs(i);
	return 0;
}
