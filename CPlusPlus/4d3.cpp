#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
bool tc[V][V]={false};
bool dfs(int i,vector<int> v,vector<int> vDegree){
	v[i]=true;
	for(auto it:adj[i])
	{
		if(vDegree[i]<k)
			vDegree[it]--;
		if(!v[it] && dfs(it,v,vDegree,k)
			vDegree[i]--;
	}
	return vDegree[i]<k;
}
int findMother(){
	vector<int> v(V,0),proc(V,0),vDegree(V,0);
	int index=-1,mindeg=INT_MAX;
	for(int i=0;i<V;i++)
	{
		vDegree[i]=adj[i].size();
		if(mindeg>vDegree[i]){
			mindeg=vDegree[i];
			index=i;
		}
	}
	dfs(index,vDegree,v,proc,k);
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<tc[i][j]<<' ';
		}
		cout<<'\n';
	}
	
}
int main()  
{
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3); 
//    addEdge(5, 2); 
//    addEdge(6, 0); 
  
    findMother();   

}  
