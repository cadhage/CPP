#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],intime(1000),outtime(1000),v(1000,0);
int t=0;
void dfs(int i,int n){
	v[i]=true;
	t++;
	intime[i]=t;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs(it,n);
		}
	}
	t++;
	outtime[i]=t;
}
bool query(int u,int v){
	return ((intime[u]<intime[v])&&(outtime[u]>outtime[v])||
	(intime[v]<intime[u])&&(outtime[v]>outtime[u]));
}
int main() 
{ 
    // Let us create above shown tree 
    int n = 9; // total number of nodes 
    //vector<int> graph[n+1]; 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[3].push_back(6); 
    adj[2].push_back(4); 
    adj[2].push_back(5); 
    adj[5].push_back(7); 
    adj[5].push_back(8); 
    adj[5].push_back(9); 
  
    // Start dfs (here root node is 1) 
    dfs(1,n); 
  
    // below are calls for few pairs of nodes 
    query(1, 5)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 9)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 6)? cout << "Yes\n" : cout << "No\n"; 
  
    return 0; 
} 
