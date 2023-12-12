#include <bits/stdc++.h>
using namespace std;
//static int V=0;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
bool dfs(int s,vector<bool> &v,vector<int> &vDegree,int k,int V){
	v[s]=true;
	for(auto it:adj[s]){
		if(vDegree[s]<k)
			vDegree[it]--;
		if(!v[it])
			if(dfs(it,v,vDegree,k,V))
				vDegree[s]--;
	}
	return vDegree[s]<k;
}
void printKCore(int k,int V){
    vector<bool> visited(V, false); 
	int mindeg = INT_MAX; 
    int startvertex; 
    vector<int> vDegree(V); 
    for (int i=0; i<V; i++) 
    { 
        vDegree[i]  = adj[i].size(); 
        if (vDegree[i] < mindeg) 
        { 
            mindeg = vDegree[i]; 
            startvertex=i; 
        } 
    } 
    dfs(startvertex, visited, vDegree, k,V); 
    for (int i=0; i<V; i++) 
        if (visited[i] == false) 
            dfs(i, visited, vDegree, k,V); 
    cout << "K-Cores : \n"; 
    for (int v=0; v<V; v++) 
    { 
        if (vDegree[v] >= k) 
        { 
            cout << "\n[" << v << "]"; 
            for (auto itr: adj[v]) 
                if (vDegree[itr] >= k) 
                    cout << " -> " << itr; 
        } 
    } 
}
int main(){
	int V=9,k=3;
  	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(1, 5); 
    addEdge(2, 3); 
    addEdge(2, 4); 
    addEdge(2, 5); 
    addEdge(2, 6); 
    addEdge(3, 4); 
    addEdge(3, 6); 
    addEdge(3, 7); 
    addEdge(4, 6); 
    addEdge(4, 7); 
    addEdge(5, 6); 
    addEdge(5, 8); 
    addEdge(6, 7); 
    addEdge(6, 8); 
    printKCore(k,V); 
	return 0;
}
