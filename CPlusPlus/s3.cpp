#include <bits/stdc++.h>
using namespace std;
#define V 5
///vector<int> adj[10000];
void dfs(bool adj[][V],vector<bool> &v,int n,int s,int start,int &count)
{
	v[s]=true;
	if(n==0){
		v[s]=false;
		if(adj[s][start]){
			count++;
			return;
		}else return;
	}
	for(int i=0;i<V;i++){
		if(!v[i]&&adj[s][i]){
			dfs(adj,v,n-1,i,start,count);
		}
	}
	v[s]=false;
}
int countCycles(bool adj[][V],int n){
	
	vector<bool> rec(V,false),v(V,false);
	int count=0;
	for(int i=0;i<V-n+1;i++){
		dfs(adj,v,n-1,i,i,count);
		v[i]=true;
	}
	return count/2;
}
int main() 
{ 
    bool graph[][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}}; 
    int n = 4; 
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n); 
    return 0; 
} 
