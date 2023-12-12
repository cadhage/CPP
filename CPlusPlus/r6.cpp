#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-9
const ll nx=3e5,mx=5e5;
ll indegree[nx],outdegree[nx];
vector<ll> adj[nx];
double ways[mx];
int main()
{
	ll n,m,r;cin>>n>>m>>r;
	assert(n<=nx &&m<=mx&&r<=n);
	r--;
	for(ll i=0;i<m;i++){
		ll u,v;cin>>u>>v;
		v--;u--;
		adj[u].push_back(v);
		indegree[v]++,outdegree[u]++;
	}
	ways[r]=1;
	list<ll> q;
	for(ll i=0;i<n;i++)
		if(indegree[i]==0)
			q.push_back(i);
	while(!q.empty()){
		ll i=q.front();
		q.pop_front();
		for(auto it:adj[i]){
			ways[it]+=ways[i]*1.0/outdegree[i];
			indegree[it]--;
			if(indegree[it]==0)
				q.push_back(it);
		}
	}
	double mx=0;int idx=0;
	for(int i=0;i<n;i++){
		if(outdegree[i]==0 && ways[i]>mx){
			mx=max(mx,ways[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(outdegree[i]==0 && abs(ways[i]-mx)<=EPS)
			cout<<i+1<<' ';
	}
	cout<<'\n';
}
