#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],v(1000,0);
stack<int> st;
void addEdge(int x,int y){
	adj[x].push_back(y);
}
void topo(int i,int n){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			topo(it,n);
		}
	}
	st.push(i);
}
int main(){
	addEdge(5,2);
	addEdge(5,0);
	addEdge(4,0);
	addEdge(4,1);
	addEdge(2,3);
	addEdge(3,1);
	for(int i=0;i<6;i++){
		if(!v[i]){
			topo(i,6);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<' ';
		st.pop();
	}
}
