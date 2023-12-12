#include <bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
vector<int> adj[10000];
vector<int> v(10000,false);
void addEdge(int v, int w) 
{ 
	v--;w--;
	adj[v].push_back(w); 
	adj[w].push_back(v);
} 

vector<int> bfs(int n){
	vector<int> level(n);
	level[0]=0;
	v[0]=true;
	list<int> q;
	q.push_back(0);
	while(!q.empty()){
		int n=q.front();
		q.pop_front();
		for(auto it:adj[n]){
			if(!v[it]){
				level[it]=level[n]+1;
				v[it]=true;
				q.push_back(it);
			}
		}
	}

	return level;
}
int main(){
    int n,m;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        addEdge(x,y);
    }
	vector<int> level=bfs(n);
    int q;cin>>q;
    vector<pair<int,int>> res;
    for(int i=0;i<q;i++){
    	int x;cin>>x;
    	x--;
    	res.push_back({x,level[x]});
	}
	sort(res.begin(),res.end(),[](auto a,auto b){
		return a.second==b.second?(a.first<b.first):a.second<b.second;	
	});
//	for(int i=0;i<res.size();i++){
//		cout<<res[i].first<<' '<<res[i].second<<'\n';
//	}
	cout<<res[0].first<<'\n';
	
////    //dfs(0);
	return 0;
}
