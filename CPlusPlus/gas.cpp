#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> adj[500];
	int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int n,m;cin>>n>>m;
        for(int j=1;j<=m;j++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
    for(int i=0;i<n;i++){
        for(auto j=adj[i].begin();j<adj[i].end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    cout<<"......................"<<endl;
}
return 0;
}
