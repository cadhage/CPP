#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1000];
vector<int> v(1000,0);
stack<int> st;
bool isReachable(int s, int d) 
{ 
    // Base case 
    if (s == d) 
      return true; 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    v[s] = true; 
    queue.push_back(s); 
  
    while (!queue.empty()) 
    { 
        s = queue.front(); 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued vertex s 
        // If a adjacent has not been visited, then mark it visited 
        // and enqueue it 
        for (auto it:adj[s]) 
        { 
            // If this adjacent node is the destination node, then  
            // return true 
            if (it.first == d) 
                return true; 
  
            // Else, continue to do BFS 
            if (!v[it.first]) 
            { 
                v[it.first] = true; 
                queue.push_back(it.first); 
            } 
        } 
    } 
      
    // If BFS is complete without visiting d 
    return false; 
} 
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		x--;y--;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
		//adjr[y].push_back(x);
	}
	int u,v;u--;v--;cin>>u>>v;
	isReachable(u,v)?cout<<"YES\n":cout<<"NO\n";
}
