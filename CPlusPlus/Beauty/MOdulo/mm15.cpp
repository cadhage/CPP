#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
void dfs(int n,int m,int visit[][MAX],int adj[][MAX],int N,int M){
	visit[n][m]=1;
	if(n+1<N &&adj[n][m]>=adj[n+1][m]&&!visit[n+1][m])
		dfs(n+1,m,visit,adj,N,M);
	if(m+1<M &&adj[n][m]>=adj[n][m+1]&&!visit[n][m+1])
		dfs(n,m+1,visit,adj,N,M);
	if(n-1>=0 &&adj[n][m]>=adj[n-1][m]&&!visit[n-1][m])
		dfs(n-1,m,visit,adj,N,M);
	if(m-1>=0 &&adj[n][m]>=adj[n][m-1]&&!visit[n][m-1])
		dfs(n,m-1,visit,adj,N,M);
}
void printMinSources(int adj[][MAX],int N,int M){
	vector<pair<int,pair<int,int>>> x;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			x.push_back(make_pair(adj[i][j],make_pair(i,j)));
		}
	}
	sort(x.begin(),x.end());
	int visit[N][MAX];
	memset(visit,false,sizeof(visit));
	for(int i=x.size()-1;i>=0;i--){
		if(!visit[x[i].second.first][x[i].second.second]){
			cout<<x[i].second.first<<" "
				<<x[i].second.second<<'\n';
				dfs(x[i].second.first,x[i].second.second
					,visit,adj,N,M);
		}
	} 
}
int main(){
	int N=3,M=3;
	int adj[N][MAX]={{1,2,3},{2,3,1},{1,1,1}};
	printMinSources(adj,N,M);
	return 0;
}
