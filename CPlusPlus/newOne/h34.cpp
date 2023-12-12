#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<vector<pair<int,int>>> g(1000);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	vector<int> val(n,0);
	for(int i=0;i<n;i++)
		cin>>val[i];
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(make_pair(val[y],y));
		g[y].push_back(make_pair(val[x],x));
	}
	for(int i=0;i<n;i++){
		sort(g[i].begin(),g[i].end());
	}
	for(int i=0;i<n;i++){
		if(g[i].size()>=k){
			cout<<g[i][g[i].size()-k].second+1<<'\n';
		}
		else{
			cout<<-1<<'\n';
		}
	}
	return 0;
}
