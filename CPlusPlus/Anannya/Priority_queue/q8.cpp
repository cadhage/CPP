#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000];
int v[1000][1000];
void addEdge(int a,int b){
	g[a].push_back(b);
	//g[b].push_back(a);
}
void DFS(int i,int j){
	v[i][j]=true;
	//cout<<i<<" ";
	for(auto it:g[j]){
		if(!v[j][it]){
			DFS(i,it);
		}
	}
}
void transitiveCloser(){
	for(int i=0;i<4;i++){
		DFS(i,i);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<v[i][j]<<" ";
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
    cout << "Transitive closure matrix is \n"; 
	transitiveCloser();
} 
