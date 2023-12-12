#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],intime(1000),outtime(1000),v(1000,0);
int t=0;
void addedge(int x,int y){
	x--;y--;
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void dfs(int i,int a[],int mn){
	mn=min(mn,a[i]);
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			dfs(it,a,mn);
		}
	}
}
void dfs_(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(!v[i]){
			int mn=a[i];
			dfs(i,a,mn);
			sum+=mn;
		}
	}
	cout<<sum<<'\n';
}
int main() 
{ 

    int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10}; 
      
    // Add edges 
    addedge(1, 2); 
    addedge(3, 4); 
    addedge(5, 6); 
    addedge(7, 8); 
    addedge(9, 10);
	int n=10; 
	dfs_(a,n); 
  
    return 0; 
} 
