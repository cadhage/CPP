#include <bits/stdc++.h>
using namespace std;
#define V 8
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
int printLevels(int l){
	vector<bool> v(V,false);
	vector<int> level(V,0);
	v[0]=true;
	list<int> q;
	q.push_back(0);
	while(!q.empty()){
		int i=q.front();
		q.pop_front();
		for(auto it:adj[i]){
			if(!v[it]){
				q.push_back(it);
				level[it]=level[i]+1;
				v[it]=true;
			}
		}
	}
	return level[l];
}
int main() 
{ 
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(3); 
    adj[1].push_back(4); 
    adj[1].push_back(5); 
    adj[2].push_back(5); 
    adj[2].push_back(6); 
    adj[6].push_back(7); 
    cout<<printLevels(6); 
  
    return 0; 
} 
