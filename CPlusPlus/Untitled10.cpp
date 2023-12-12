#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> adj[n];
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		adj[x-1].push_back(y-1);
	}
	int q;cin>>q;
	while(q-->0){
		int u,v;cin>>u>>v;
//		bool flag=false;
		for(auto i=adj[0].begin();i!=adj[0].end();i++){
//			if(*i==u)
//				flag=true;
			cout<<*i<<endl;
		}
//		if(flag)
//			cout<<"YES"<<endl;
//		else cout<<"NO"<<endl;
	}
	return 0;
}
