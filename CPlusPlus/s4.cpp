#include <bits/stdc++.h>
using namespace std;
#define V 3
bool twoColorUtil(vector<int> adj[],int i,int n,vector<int> color){
	color[i]=0;
	list<int> q;
	q.push_back(i);
	while(!q.empty()){
		i=q.front();
		//q.pop()#i;
		for(auto it:adj[i]){
			if(color[it]==-1){
				color[it]=1-color[i];
				q.push_back(it);
			}else if(color[it]==color[i])
				return false;
		}
	}
	return true;
}
int twoColor(vector<int> adj[],int n){
	vector<int> color(n+1,-1);
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(!twoColorUtil(adj,i,n,color))
				return false;
		}
	}
	return true;
}
bool isOddSum(int adj[][V],int n,int m){
	vector<int> G[2*n];
	int pseudo=n+1;
	int pseudo_count=0;
	for(int i=0;i<m;i++){
		if(adj[i][2]%2==1){
			int u=adj[i][0];
			int v=adj[i][1];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		else {
			int u=adj[i][0];
			int v=adj[i][1];
			G[u].push_back(pseudo);
			G[pseudo].push_back(u);
			G[v].push_back(pseudo);
			G[pseudo].push_back(v);
			pseudo_count++;
			pseudo++;
		}
	}
	return twoColor(G,n+pseudo_count);
}
int main() 
{ 
 int n = 4, m = 3; 
    int info[4][3] = {{1, 2, 12}, 
                     {2, 3, 1}, 
                     {4, 3, 1}, 
                     {4, 1, 20}};  
    if (isOddSum(info, n, m) == true) 
        cout << "No\n"; 
    else
        cout << "Yes\n"; 
    return 0; 
} 
