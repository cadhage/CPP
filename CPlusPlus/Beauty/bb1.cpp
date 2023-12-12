#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
}
//stack<int> st;
void topoSort(int i,stack<int> &st,vector<bool> &v,int V){
	v[i]=true;
	for(auto it:adj[i]){
		if(!v[it]){
			topoSort(it,st,v,V);
		}
	}
	st.push(i);
}
void topo_Sort(int V){
	vector<bool> v(V,false);
	stack<int> st;
	for(int i=0;i<V;i++){
		if(!v[i])
			topoSort(i,st,v,V);
	}
	while(!st.empty()){
		cout<<(char)('a'+st.top())<<' ';
		st.pop();
	}
}
void printOrder(string words[],int m,int V){
	for(int i=0;i<V-1;i++){
		string word1=words[i],word2=words[i+1];
		for(int j=0;j<min(word1.size(),word2.size());j++){
			if(word1[j]!=word2[j]){
				addEdge(word1[j]-'a',word2[j]-'a');
				break;
			}
		}
	}
	
	topo_Sort(V);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string words[]={"caa","aaa","aab"};
	printOrder(words,3,3);
	return 0;
}
