#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],intime(1000),outtime(1000),v(1000,0).degree(1000);
int t=0;
void addedge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
	degree[x]++;
	degree[y]++;
}
void bfs(int n){
	list<int> q;
	for(int i=0;i<n;i++){
		if(degree[i]==1)
			q.push_back(i);	
	}
	while(n>2){
		while(!q.empty()){
			int t=q.front();
			q.pop_front();
			n--;
			for(auto it:adj[t]){
				degree[it]--;
				if(degree[it]==1){
					q.push_back(it);
				}
			}
		}
	}
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop_front();
	}
}
int main() 
{ 
    addedge(0, 3); 
    addedge(1,3);
    addedge(2, 3); 
    addedge(4, 3); 
    addedge(5, 4); 
	bfs(6); 
    return 0; 
} 
