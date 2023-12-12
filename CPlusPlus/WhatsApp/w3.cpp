#include<bits/stdc++.h>
using namespace std;
void printLevels(vector<int> g[],int V,int x){
	int level[V];
	bool v[V];
	queue<int> q;
	q.push(x);
	level[x]=0;
	v[x]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:g[x]){
			if(!v[it]){
				q.push(it);
				level[it]=level[x]+1;
				v[it]=true;
			}
		}
	}
	cout<<"Nodes"<<" "<<"Level"<<"\n";
	for(int i=0;i<V;i++){
		cout<<" "<<i<<" --> "<<level[i]<<'\n';
	}
}
int main() 
{ 
    // adjacency graph for tree 
    int V = 8; 
    vector<int> graph[V]; 
  
    graph[0].push_back(1); 
    graph[0].push_back(2); 
    graph[1].push_back(3); 
    graph[1].push_back(4); 
    graph[1].push_back(5); 
    graph[2].push_back(5); 
    graph[2].push_back(6); 
    graph[6].push_back(7); 
  
    // call levels function with source as 0 
    printLevels(graph, V, 0); 
  
    return 0; 
} 
