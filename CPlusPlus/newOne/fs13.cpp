#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> v(1000,false);
vector<bool> r(1000,false);
int V=6;
stack<int> st;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
void d(int i){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it])
			d(it);
	}
	st.push(i);
}
void isCyclic(){
	for(int i=0;i<V;i++)
	{
		if(!v[i])
			d(i);
	}
	while(!st.empty()){	
		cout<<st.top()<<' ';
		st.pop();
	}
}

int main(){
	addEdge(5,2);
	addEdge(5,0);
	addEdge(4,0);
	addEdge(4,1);
	addEdge(2,3);
	addEdge(3,1); 
    isCyclic();
    
    return 0; 
	return 0;
}
