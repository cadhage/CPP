#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int> v(1000,-1);
vector<bool> r(1000,false);
#define V 4
bool b=true;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
bool d(int G[][V],int i){
	v[i]=1;
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(G[u][u])
			return false;
		for(int j=0;j<V;j++){
			if(G[u][j]&&v[j]==-1){
				q.push(j);
				v[j]=1-v[u];
			}
			if(G[u][j]&&v[u]==v[j])
				return false;
		}
	}
	return true;
}
int main(){
	int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    d(G,0) ? cout << "Yes" : cout << "No"; 
    return 0; 
}
