#include <bits/stdc++.h>
using namespace std;
void dfs(int i,int ans[],vector<int> adj[]){
	ans[i]=1;
	for(auto it:adj[i]){
		if(!ans[adj[i][it]]){
			dfs(adj[i][it],ans,adj);
		}
	}
}
void printBinaryPalindrome(int n,int k){
	int a[n],ans[n]={0};
	vector<int> adj[k];
	for(int i=0;i<n;i++){
		a[i]=i%k;
	}
	for(int i=0;i<n/2;i++){
		adj[a[i]].push_back(a[n-i-1]);
		adj[a[n-i-1]].push_back(a[i]);
	}
	dfs(0,ans,adj);
	for(int i=0;i<n;i++){
		cout<<ans[a[i]]<<' ';
	}
}
int main(){
	int n=10,k=4;
	printBinaryPalindrome(n,k);
	return 0;
}
