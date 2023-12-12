#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000],v(1000,0);
void dfs(int i,int &k){
	v[i]=1;
	for(auto it:adj[i]){
		if(!v[it]){
			k++;
			dfs(it,k);
		}
	}
}
int countNonAccessible(int n){
	int ans=0;
	for(int i=1;i<=n*n;i++){
		if(!v[i]){
			//v[i]=1;
			int k=1;
			dfs(i,k);
			ans+=k*(n*n-k);
		}
	}
	return ans;
}
void insertpath(int x1,int y1,int x2,int y2,int n){
	int a=(x1-1)*n+y1;
	int b=(x2-1)*n+y2;
	adj[a].push_back(b);
	adj[b].push_back(a);
}
int main() 
{ 
    int n = 2; 
   // vector<int> graph[N*N + 1]; 
    insertpath(1, 1, 1, 2,n); 
    insertpath(1, 2, 2, 2,n); 
    cout << countNonAccessible(n) << endl; 
    return 0; 
} 
