#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100000];
vector<bool> v(100,false);
//void dfs(int i){
//	v[i]=true;
//	cout<<i<<' ';
//	for(auto it:g[i]){
//		if(!v[it]){
//			v[it]=true;
//			dfs(it);
//		}
//	}
//}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;cin>>N;
	for(int i=0;i<N;i++){
		int x;cin>>x;
	}
	for(int i=0;i<N-1;i++){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		g[a].emplace_back(make_pair(b,c));
		g[b].emplace_back(make_pair(a,c));
	}
	for(int i=0;i<N;i++){
		for(auto &it:g[i]){
			cout<<i<<"->"<<it.first<<'$'<<it.second<<' ';
		} 
		cout<<'\n';
	}
	return 0;
}
