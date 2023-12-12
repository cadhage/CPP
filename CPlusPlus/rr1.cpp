#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
#define INFS INT_MAX
vector<pair<int,int>> adj[1000];
void addEdge(int x,int y,int z){
	adj[x].push_back(make_pair(y,z));
}
void topo(int i,vector<int> &v,stack<int> &st,int n){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it.first]){
			topo(it.first,v,st,n);
		}
	}
	st.push(i);
}
void longestPath(int s,int n){
	vector<int> v(n,0);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(!v[i]){
			topo(i,v,st,n);
		}
	}
	vector<int> dist(n,INF);
	dist[s]=0;
	while(!st.empty()){
		int i=st.top();
		st.pop();
		if(dist[i]!=INF){
			for(auto it:adj[i]){
				if(dist[it.first]<dist[i]+it.second)
					dist[it.first]=dist[i]+it.second;
			}
		}	
	}
	for(int i=0;i<n;i++){
		if(dist[i]==INF)
			cout<<"INT_MAX\n";
		else cout<<dist[i]<<'\n'; 
	}
}
int main(){
    addEdge(0, 1, 5); 
    addEdge(0, 2, 3); 
    addEdge(1, 3, 6); 
    addEdge(1, 2, 2); 
    addEdge(2, 4, 4); 
    addEdge(2, 5, 2); 
    addEdge(2, 3, 7); 
    addEdge(3, 5, 1); 
    addEdge(3, 4, -1); 
    addEdge(4, 5, -2); 
    int s = 1;
    cout<<"Longest Path\n";
    longestPath(s,6);
//    cout<<"Shortest Path\n";
//    shortestPath(s,6);
}
