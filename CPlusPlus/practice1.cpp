#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> adj[500];
	vector<pair<int,int> >vect;
	int n,rez,pos[500];
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        vect.push_back({m,i});
        for(int j=1;j<=m;j++){
            int u;cin>>u;
            adj[i].push_back(u);
        }
    }
    sort(vect.begin(),vect.end());
    for(int i=0;i<n;i++){
        int id=vect[i].second;
        cout<<id<<endl;
        if(pos[id]==0){
            for(auto j=adj[id].begin();j<adj[id].end();j++){
                pos[*j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
		if(pos[i]==0)
			rez++;
    cout<<rez;
 
return 0;
}
