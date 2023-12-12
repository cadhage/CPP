#include <bits/stdc++.h>
using namespace std;
#define V 6
vector<int> adj[1000];
vector<int> in(1000,0);
void addEdge(int a,int b){
	adj[a].push_back(b);
	in[b]++;
}
bool dfs(vector<int> &v,vector<int> &res){
	bool flag=false;
	for(int i=0;i<V;i++){
		if(v[i]==0&& in[i]==0){
			for(auto it:adj[i])
				in[it]--;
			res.push_back(i);
			v[i]=1;
			dfs(v,res);
			res.erase(res.end()-1);
			v[i]=0;
			for(auto it:adj[i])
				in[it]++;
			flag=true;
		}
	}
	if(!flag){
		for(int it:res){
			cout<<it<<' ';
		}
		cout<<'\n';
	}
}
void isCyclic(){
	vector<int> v(V,0),res;
	dfs(v,res);
	//return false;
}
int main() 
{  
    addEdge(5, 2); 
    addEdge(5, 0); 
    addEdge(4, 0); 
    addEdge(4, 1); 
    addEdge(2, 3); 
    addEdge(3, 1); 
	isCyclic();
    return 0; 
} 
