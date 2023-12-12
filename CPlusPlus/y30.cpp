#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void greedyColoring(int n){
   vector<int> res(n,-1),v(n,0);
   res[0]=0;
   for(int i=1;i<n;i++){
   		for(auto it:adj[i]){
   			if(res[it]!=-1){
   				v[res[it]]=1;	
			}	
		}
		int r=-1;
		for(int j=0;j<n;j++){
			if(!v[j]){
				r=j;
				break;
			}
		}
		res[i]=r;
		for(auto it:adj[i]){
   			if(res[it]!=-1){
   				v[res[it]]=0;	
			}	
		}
   }
   for(int i=0;i<n;i++){
   	cout<<i<<"->"<<res[i]<<'\n';
   }
}
int main(){
	int n=5;
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    cout << "Coloring of graph 1 \n"; 
    greedyColoring(n); 
	return  0;
}
