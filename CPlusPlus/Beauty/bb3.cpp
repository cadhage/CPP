#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
vector<pair<int,int>> adj[1000];
void addEdge(int x,int y,int z){
	adj[x].push_back(make_pair(y,z));
}
//stack<int> st;
void topoSort(int i,stack<int> &st,vector<bool> &v,int V){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it.first]){
			topoSort(it.first,st,v,V);
		}
	}
	st.push(i);
}
void topo_Sort(int i,int V){
	vector<bool> v(V,false);
	stack<int> st;
	for(int i=0;i<V;i++){
		if(!v[i])
			topoSort(i,st,v,V);
	}
	int dist[V];
    for (int i = 0; i < V; i++)  
        dist[i] = INF;  
    dist[i] = 0;   
    while (!st.empty()) {  
        int u = st.top();  
        st.pop();    
        if (dist[u] != INF) {  
            for (auto i:adj[u])  
                if (dist[i.first] < dist[u] + i.second)  
                    dist[i.first] = dist[u] + i.second;  
        }  
    }   
    for (int i = 0; i < V; i++)  
        (dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V=6;
	addEdge(0,1,5);
	addEdge(0,2,3);
	addEdge(1,3,6);
	addEdge(1,2,2);
	addEdge(2,4,4);
	addEdge(2,5,2);
	addEdge(2,3,7);
	addEdge(3,5,1);
	addEdge(3,4,-1);
	addEdge(3,4,-1);
	addEdge(4,5,-2);
	int i=1;
	topo_Sort(i,V);
	return 0;
}
