#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int a,int b){
	adj[a].push_back(b);
}

void rmvEdge(int u,int v){
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i]==v)
			adj[u][i]=-1;
	}
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]==u)
			adj[v][i]=-1;
	}
}
int DFSCount(int i,vector<bool> &v){
	v[i]=true;
	int count=1;
	for(auto it:adj[i]){
		if(!v[i])
			count+=DFSCount(it,v);
	}
	return count;
}
bool isValidEdge(int u,int v){
	int count=0;
	for(auto it:adj[u]){
		if(it!=-1)
			count++;
	}
	if(count==1)
		return true;
	vector<bool> visit(V,false);
	int count1=DFSCount(u,visit);
	rmvEdge(u,v);
	for(int i=0;i<V;i++)
		visit[i]=false;
	int count2=DFSCount(u,visit);
	addEdge(u,v);
	return count1>count2?false:true;
}
void printEulerUtil(int u) 
{ 
    for (auto it:adj[u])
    { 
        int v = it; 
        if (v != -1 && isValidEdge(u, v)) 
        { 
            cout << u << "-" << v << " "; 
            rmvEdge(u, v); 
            printEulerUtil(v); 
        } 
    }
}
void printEulerTour() 
{ 
    // Find a vertex with odd degree 
    int u = 0; 
  
    for (int i = 0; i < V; i++) 
        if (adj[i].size() & 1) 
        { 
            u = i; 
            break; 
        } 
  
    // Print tour starting from oddv 
    printEulerUtil(u); 
    cout << endl; 
} 
int main(){
	cout << "\nSCCs in third graph \n";  
    addEdge(0, 1); 
    addEdge(0, 2);  
    addEdge(1, 2); 
    addEdge(2, 3);
    printEulerTour(); 
	return 0;
}
