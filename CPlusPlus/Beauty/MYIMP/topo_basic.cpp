#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int indegree[1000];
vector<vector<int>> sol;
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
void dfs(vector<int> &res,vector<bool> &v,int n){
	bool flag=false;
	for(int i=0;i<n;i++){
		if(indegree[i]==0 && !v[i]){
			for(auto it:adj[i])
				indegree[it]--;
			res.push_back(i);
			v[i]=true;
			dfs(res,v,n);
			v[i]=false;
			res.erase(res.end()-1);
			for(auto it:adj[i])
				indegree[it]++;
			flag=true;
		}
	}
	if (!flag) 
    { 
    	sol.push_back(res);
//        for (int i = 0; i < res.size(); i++) 
//            cout << res[i] << " "; 
//        cout << endl; 
    } 
}
void alltopologicalSort(int n) 
{ 
    // Mark all the vertices as not visited 
    vector<bool> v(n,false); 
    vector<int> res; 
    dfs(res,v,n); 
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
	//	x--;y--;
		addEdge(x,y);
	}
  //  cout << "Following is a Topological Sort of the given graph \n"; 
    alltopologicalSort(n);
//    for(int i=0;i<n;i++){
//    	for(auto it: sol[i])
//    		cout<<it<<' ';
//    	cout<<'\n';
//	}
	return 0;
}
