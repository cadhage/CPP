#include <bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
vector<int> adj[1000000];
void addEdge(int v, int w) 
{ 
	v--;w--;
	adj[v].push_back(w); 
//	adj[w].push_back(v);
} 

vector<int> bfs(int i,int n,vector<bool> &v){
	vector<int> level(n);
	level[i]=0;
	v[i]=true;
	list<int> q;
	q.push_back(i);
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
    int n,m,r;cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        addEdge(x,y);
    }
    r--;
    vector<int> count(n,0);
    for(int i=r;i<n;i++){
    	vector<bool> v(n,false);
    	if(!v[i]){
			vector<int> level=bfs(i,n,v);
			int mx=0,mx_i=-1;
			for(int i=0;i<level.size();i++){
				if(level[i]>=mx && level[i]!=0){
					mx=level[i];
					mx_i=i;
				}
			//	cout<<level[i]<<' ';
			}
			//cout<<mx_i<<'\n';
			count[mx_i]++;
			mx=0,mx_i=-1;
		}
	}
	sort(count.begin(),count.end(),[](int a,int b){
		return a<b;
	});
	int max=*max_element(count.begin(),count.end());
	for(int i=0;i<n;i++){
		if(count[i]==max){
			cout<<i+1<<' ';
		}
	}
	return 0;
}
