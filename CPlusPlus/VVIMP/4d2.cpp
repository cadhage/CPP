#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
bool tc[V][V]={false};
void dfs(int i,int j){
	tc[i][j]=true;
	for(auto it:adj[i])
	{
		if(!tc[i][it])
			dfs(i,it);
	}
}
int findMother(){
 for (int i = 0; i < V; i++) 
        dfs(i, i); // Every vertex is reachable from self. 
  
    for (int i=0; i<V; i++) 
    { 
        for (int j=0; j<V; j++) 
            cout << tc[i][j] << " "; 
        cout << endl; 
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
