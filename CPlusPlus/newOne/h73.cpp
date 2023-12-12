// C++ program for Minimum swap required 
// to convert binary tree to binary search tree 
#include<bits/stdc++.h>
using namespace std;  
vector<int> adj[1000];
vector<int> trans[1000];
void transposeGraph(int n){
	for(int i=0;i<n;i++){
		for(auto it:adj[i]){
			trans[it].push_back(i);
		}
	}
}
void DFS2(int s,vector<bool> v){
	v[s]=true;
	for(auto it:trans[s]){
		if(!v[s]){
			DFS2(it,v);
		}
	}	
}
void DFS1(int s,vector<bool> v,stack<int> st){
	v[s]=true;
	for(auto it:adj[s]){
		if(!v[s]){
			DFS1(it,v,st);
		}
	}
	st.push(s);
}
void printSCC(int n){
	stack<int> st;
	vector<bool> v(n,false);
	for(int i=0;i,n;i++){
		if(!v[i]){
			DFS1(i,v,st);
		}
	}
	transposeGraph(n);
	fill(v.begin(),v.end(),false);
	while(!st.empty()){
		int x=st.top();
		st.pop();
		if(!v[x]){
			DFS2(x,v);
			cout<<'\n';
		}
	}
	
}
int main() 
{ 
	int v = 5; 
    vector<int> adj[v]; 
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);
    printSCC(v);
   
} 

