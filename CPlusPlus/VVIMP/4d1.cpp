#include<bits/stdc++.h> 
using namespace std; 
#define V 9
vector<int> adj[10000]; 
bool dfs(int i, vector<bool> &v, 
					vector<int> &vDegree, int k) 
{ 
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[i]&&dfs(it,v,vDegree,k))
			vDegree[i]--;
		if(vDegree[i]<k)
			vDegree[it]--;
	}
} 
void addEdge(int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 
void printKCores(int k) 
{ 
	vector<bool> v(V,false);
	vector<int> vDegree(V,0);
	int mn=INT_MAX,index=-1;
	for(int i=0;i<V;i++){
		vDegree[i]=adj[i].size();
		if(mn>vDegree[i])
		{
			mn=vDegree[i];
			index=i;
		}
	}
	dfs(index,v,vDegree,k);
	for(int i=0;i<V;i++){
		if(!v[i]){
			dfs(i,v,vDegree,k);
		}
	}
	for(int i=0;i<V;i++){
		if(vDegree[i]>=k){
			cout<<"\n["<<i<<"]";
			for(auto it:adj[i]){
				if(vDegree[it]>=k){
					cout<<"->"<<it;
				}
			}
		}
	}
} 
int main()  
{
	int k = 3; 
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
    printKCores(k); 
}  
