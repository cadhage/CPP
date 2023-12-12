#include <bits/stdc++.h>
using namespace std;
#define V 5
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
void _dfs(int i,vector<bool> &v){
	stack<int> st;
	st.push(i);
	while(!st.empty()){
		i=st.top();
		st.pop();
		if(!v[i])
		{
			cout<<i<<'\n';
			v[i]=true;
		}
		for(auto it:adj[i]){
			if(!v[it])
				st.push(it);
		}
	}
}
void DFS(){
	vector<bool> v(V,false);
	for(int i=0;i<V;i++)
		if(!v[i])
			_dfs(i,v);
}
int main() 
{ 
    //Graph g(5);  // Total 5 vertices in graph 
    addEdge(1, 0); 
    addEdge(2, 1); 
    addEdge(3, 4); 
    addEdge(4, 0); 
  
    cout << "Following is Depth First Traversal\n"; 
    DFS(); 
  
    return 0; 
} 
