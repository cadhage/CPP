#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<int> g[100000];
bool v[10000];
int from[10000];
void bfs(int x,int y){
	v[x]=true;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		x=q.front();
		cout<<x<<' ';
		q.pop();
		for(auto it:g[x]){
			if(!v[it]){
				from[it]=x;
				q.push(it);
				v[it]=true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,t,c;cin>>n>>m>>t>>c;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int x,y;cin>>x>>y;
	x--,y--;
	bfs(x,y);
	for(int i=0;i<n;i++){
		cout<<from[i]<<' ';
	}
}
