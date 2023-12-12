#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int V=3;
vector<int> visited(10000,false);
void addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
}  
void topologicalSortUtil(int v, stack<int> &st) 
{ 
    visited[v] = true; 
    for (auto i :adj[v]) 
        if (!visited[i]) 
            topologicalSortUtil(i, st); 
  	st.push(v); 
} 
void topologicalSort() 
{ 
    stack<int> st;   
    for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            topologicalSortUtil(i,st); 
    while (st.empty() == false) 
    { 
        cout << (char) ('a' + st.top()) << " "; 
        st.pop(); 
    } 
} 
void printOrder(string a[],int n,int alpha){
	for(int i=0;i<n-1;i++){
		string word1=a[i],word2=a[i+1];
		for(int j=0;j<min(word1.length(),word2.length());j++){
			if(word1[j]!=word2[j]){
				addEdge(word1[j]-'a',word2[j]-'a');
				break;
			}
		}
	}
	topologicalSort();
}
int main(){
	string words[] = {"caa", "aaa", "aab"}; 
    printOrder(words, 3, 3);
	return 0;
}
