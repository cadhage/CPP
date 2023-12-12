// C++ program to print all topological sorts of a graph 
#include <bits/stdc++.h> 
using namespace std; 
vector<int> adj[1000];
vector<int> indegree(1000,0);
vector<vector<int>> sol;
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
void alltopologicalSortUtil(vector<int>& res, 
								bool visited[],int V) 
{ 
	// To indicate whether all topological are found 
	// or not 
	bool flag = false; 

	for (int i = 0; i < V; i++) 
	{ 
		// If indegree is 0 and not yet visited then 
		// only choose that vertex 
		if (indegree[i] == 0 && !visited[i]) 
		{ 
			for (auto j:adj[i]) 
				indegree[j]--; 

			// including in result 
			res.push_back(i); 
			visited[i] = true; 
			alltopologicalSortUtil(res, visited,V); 

			// resetting visited, res and indegree for 
			// backtracking 
			visited[i] = false; 
			res.erase(res.end() - 1); 
			for (auto j:adj[i]) 
				indegree[j]++; 

			flag = true; 
		} 
	} 

	// We reach here if all vertices are visited. 
	// So we print the solution here 
	if (!flag) 
	{ 
		sol.push_back(res);
//		for (int i = 0; i < res.size(); i++) 
//			cout << res[i] << " "; 
//		cout << endl; 
	} 
} 

// The function does all Topological Sort. 
// It uses recursive alltopologicalSortUtil() 
void alltopologicalSort(int V) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	vector<int> res; 
	alltopologicalSortUtil(res, visited,V); 
} 
int main() 
{ 
	int V,m;cin>>V>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		addEdge(x,y);
	}
	alltopologicalSort(V); 
	sort(sol.begin(),sol.end());
//	for(int i=0;i<sol.size();i++){
		for(auto it:sol[0])
			cout<<it+1<<' ';
		cout<<'\n';
//	}
	return 0; 
} 

