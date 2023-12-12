#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
vector<string> color;
vector<int> d;
vector<int> p;
void BFSFullUtil(vector<int> adj[],int x){
	queue<int> q;
	q.push(x);
	d[x]=0;
	color[x]="Green";
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(auto it:adj[x]){
			if(color[it]=="White"){
				color[it]="Green";
				d[it]=d[x]+1;
				p[it]=x;
				q.push(it);
			}
		}
	}
	color[x]="Red";
}
void BFSFull(vector<int> adj[],int n){
	color.assign(n,"White");
	d.assign(n,0);
	p.assign(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]=="White"){
			BFSFullUtil(adj,i);
		}
	}
}
int main() 
{ 
    // Graph with 7 nodes and 6 edges. 
    int n = 7; 
          
    // The Graph vector 
    vector <int> g[n]; 
      
    addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 1, 4); 
    addEdge(g, 2, 5); 
    addEdge(g, 2, 6); 
  
    BFSFull(g, n); 
  
    return 0; 
} 
