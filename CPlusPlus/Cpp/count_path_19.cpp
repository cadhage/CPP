#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
const int MAX=100;
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	graph[x].push_back(y);
}
void dfs(int i,int d,int &ans,int path[]){
	v[i]=1;
	path[ans]=i;
	ans++;
	if(i==d){
		for(int i=0;i<ans;i++){
			cout<<path[i]<<' ';
		}
		cout<<'\n';
	}
	for(auto it:graph[i]){
		if(!v[it]){
			dfs(it,d,ans,path);
		}
	}
	ans--;
	v[i]=0;
}
int main() 
{ 
  addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(0, 3); 
    addEdge(2, 0); 
    addEdge(2, 1); 
    addEdge(1, 3); 
  
    int s = 2, d = 3,c=0; 
    int path[4];
    dfs(s, d,c,path); 
    cout<<c<<'\n';
    return 0; 
}
