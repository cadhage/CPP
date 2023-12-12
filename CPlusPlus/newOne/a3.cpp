#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool V[1000];
void addEdge(int a,int b){
	adj[a].push_back(b);
}
int c=0;
int inTime[1000];
int outTime[1000];
void dfs(int i) 
{ 
    V[i]=true;
	c++;
	inTime[i]=c;
	for(auto it:adj[i]){
		if(!V[it]){
			dfs(it);
		}
	} 
	c++;
	outTime[i]=c;
}   
bool query(int a,int b){
	return ((inTime[a]>inTime[b] && outTime[a]<outTime[b])||
	(inTime[b]>inTime[a] && outTime[b]<outTime[a]));
}
int main() 
{ 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(3, 6); 
    addEdge(2, 4); 
    addEdge(2, 5); 
    addEdge(5, 7);
	addEdge(5,8);
	addEdge(5,9); 
   	dfs(1);
   	query(1, 5)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 9)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 6)? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
}
