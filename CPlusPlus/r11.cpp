#include <bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
vector<int> adj[10000];
vector<int> adj1[10000];
void addEdge(int v, int w) 
{ 
	v--;w--;
	adj[v].push_back(w); 
//	adj[w].push_back(v);
} 
void getTranspose(int n){
	for(int i=0;i<n;i++){
		for(auto it:adj[i]){
			adj1[it].push_back(i);
		//	adj1[i].push_back(it);
		}
	}
}
void dfs(int i,vector<bool> &v,stack<int> &st){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it])
			dfs(it,v,st);
	}
	st.push(i);
}
void _dfs(int i,vector<bool> &v,int &c){
	v[i]=true;
	c++;
	cout<<i<<' ';
	for(auto it:adj1[i]){
		if(!v[it]){
			_dfs(it,v,c);
		}
	}
}
void print(int n){
	vector<bool> v(n,false);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(!v[i])
			dfs(i,v,st);
	}
	for(int i=0;i<n;i++)
		v[i]=false; 
	int c=0,count=0,even=0,odd=0;
	while(!st.empty()){
		int i=st.top();
		st.pop();
		if(!v[i]){
			_dfs(i,v,count);
			cout<<'\n';
		}
	}
//	cout<<odd-even;
} 
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        addEdge(x,y);
    }
    getTranspose(n);
    print(n);
	return 0;
}
