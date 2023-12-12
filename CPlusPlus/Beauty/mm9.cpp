#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
//	adj[y].push_back(x);
}
void dfs_intrative(int i,int V){
	vector<bool> v(V,false);
	stack<int> st;
	st.push(i);
	while(!st.empty()){
		i=st.top();
		st.pop();
		if(!v[i]){
			cout<<i<<' ';
			v[i]=1;
		}
		for(auto it:adj[i]){
			if(!v[it])
				st.push(it);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V=6;
	addEdge(1,0);
	addEdge(0,2);
	addEdge(2,1);
	addEdge(0,3);
	addEdge(1,4);
	dfs_intrative(0,V);
	return 0;
}
