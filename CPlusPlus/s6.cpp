#include <bits/stdc++.h>
using namespace std;
#define V 6
vector<int> adj[1000];
vector<int> indegree(V,0);
void addEdge(int a,int b){
	adj[a].push_back(b);
	indegree[b]++;
}
void _allTopologicalSort(vector<bool> v,vector<int> res){
	bool flag=false;
	for(int i=0;i<V;i++){
		if(indegree[i]==0 &&!v[i]){
			for(auto it:adj[i]){
				indegree[it]--;
			}
			res.push_back(i);
			v[i]=true;
			_allTopologicalSort(v,res);
			v[i]=false;
			res.erase(res.end()-1);
			for(auto it:adj[i])
				indegree[it]++;
			flag=true;
		}
	}
	if(!flag){
		for(int i=0;i<res.size();i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}
}
void allTopologicalSort(){
	vector<bool> v(V,false);
	vector<int> res;
	_allTopologicalSort(v,res);	
}
int main() 
{ 
 	addEdge(5,2);
 	addEdge(5,0);
 	addEdge(4,0);
 	addEdge(4,1);
 	addEdge(2,3);
 	addEdge(3,1);
 	allTopologicalSort();
    return 0; 
} 
