#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1000];
vector<bool> v(1000,false);
vector<bool> r(1000,false);
#define INF 999
vector<int> dist(1000,INF);
#define V 6
stack<int> st;
void addEdge(int a,int b,int c){
	adj[a].push_back({b,c});
}
void d(int i){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it.first]){
			d(it.first);
		}
	}
	st.push(i);
}
void longestPath(int s){
	for(int i=0;i<V;i++){
		if(!v[i]){
			d(i);
		}
	}
	dist[s] = 0; 
    while (!st.empty()) { 
        int u = st.top(); 
        st.pop(); 
        if (dist[u] !=INF) { 
            for (auto it:adj[u]) 
                if (dist[it.first] < dist[u] + it.second) 
                    dist[it.first] = dist[u] + it.second; 
        } 
    } 
    for (int i = 0; i < V; i++) 
        (dist[i] ==INF) ? cout << "INF " : cout << dist[i] << " "; 
}
int main () 
    { 
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
	    cout << "Following are longest distances from "
	            "source vertex "
	         << s << " \n"; 
	    longestPath(s); 
        return 0;
    } 
