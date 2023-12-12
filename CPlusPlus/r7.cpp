#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-9
const ll nx=1e5,mx=1e5,bx=1e9;
void alltopologicalSortUtil(vector<int>& res, 
								bool visited[],int V,vector<int> adj[],vector<int> &indegree,vector<vector<int>> &sol) 
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
			alltopologicalSortUtil(res, visited,V,adj,indegree,sol); 

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
void alltopologicalSort(vector<int> adj[],vector<int> indegree,int V) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	vector<int> res; 
	vector<vector<int>> sol;
	alltopologicalSortUtil(res, visited,V,indegree,adj,sol); 
} 
bool cycle(ll i,ll n,vector<ll> adj[],vector<ll> &v,vector<ll> &rec){
	v[i]=1;
	rec[i]=1;
	for(auto it:adj[i]){
		if(!v[it] && cycle(it,n,adj,v,rec))
			return true;
		if(rec[it])
			return true;
	}
	rec[i]=0;
	return false;
}
int main()
{
	ll tt;cin>>tt;
	while(tt--){
		ll n,m;cin>>n>>m;
		assert(n<=nx && m<=mx);
		vector<ll> a(n);
		vector<ll> adj[n],v(n,0),rec(n,0),res(n,0);
		vector<ll> indegree(n,0);
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<m;i++){
			int x,y;char c;cin>>x>>c>>y;
			x--,y--;
			if(c=='<'){
				adj[x].push_back(y);
				indegree[y]++;
			}
			else{
				adj[y].push_back(x);
				indegree[x]++;
			}
		}
		bool flag=false;
		for(int i=0;i<n;i++){
			if(!v[i] && cycle(i,n,adj,v,rec))
				flag=true;
		}
		if(!flag){
			cout<<"YES\n";
			alltopologicalSort(adj,indegree,n);
		}
		else cout<<"NO\n"; 	
	}
}
