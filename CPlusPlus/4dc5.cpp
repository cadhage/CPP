#include <bits/stdc++.h>
using namespace std;
#define V 5
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
int ct[2]={0};
void _dfs(int i,int p,int color){
	ct[color]++;
	for(auto it:adj[i]){
		if(it!=p)
			_dfs(it,i,1-color);
	}

}
void DFS(){
	_dfs(1,0,0);
	cout<<(ct[0]*ct[1]-(V-1));
}
int main() 
{ 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(4); 
    adj[3].push_back(5);
    cout << "Following is Depth First Traversal\n"; 
    DFS(); 
  
    return 0; 
} 
