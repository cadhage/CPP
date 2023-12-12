#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,int>> adj[],int i,int prev,int &max_l,vector<int> &v){
	v[i]=1;
	int curr=0;
	for(pair<int,int> it:adj[i]){
		if(v[it.first]==0){
			curr=prev+it.second;
			dfs(adj,it.first,curr,max_l,v);
		}
	}
	if(max_l<curr)
		max_l=curr;
	curr=0;
}
int longestCable(vector<pair<int,int>> graph[], int n){
	int max_l=0;
	for(int i=1;i<=n;i++){
		vector<int> v(n+1,0);
		dfs(graph,i,0,max_l,v);
	}
	return max_l;
}
int main() 
{ 
    // n is number of cities 
    int n = 6; 
  
    vector< pair<int,int> > graph[n+1]; 
  
    // create undirected graph 
    // first edge 
    graph[1].push_back(make_pair(2, 3)); 
    graph[2].push_back(make_pair(1, 3)); 
  
    // second edge 
    graph[2].push_back(make_pair(3, 4)); 
    graph[3].push_back(make_pair(2, 4)); 
  
    // third edge 
    graph[2].push_back(make_pair(6, 2)); 
    graph[6].push_back(make_pair(2, 2)); 
  
    // fourth edge 
    graph[4].push_back(make_pair(6, 6)); 
    graph[6].push_back(make_pair(4, 6)); 
  
    // fifth edge 
    graph[5].push_back(make_pair(6, 5)); 
    graph[6].push_back(make_pair(5, 5)); 
  
    cout << "Maximum length of cable = "
         << longestCable(graph, n); 
  
    return 0; 
} 
