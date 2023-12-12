#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void Color(int V){
	vector<int> result(V,-1);
	result[0]=0;
	vector<bool> available(V,false);
	for(int i=1;i<V;i++){
		for(auto it:adj[i]){
			if(result[it]!=-1){
				available[result[it]]=true;
			}
		}
		int cr=0;
		for(int it=0;it<V;it++){
			if(!available[it])
			{
				cr=it;
				break;
			}
		}
		result[i]=cr;
		for(auto it:adj[i]){
			if(result[it]!=-1){
				available[result[it]]=false;
			}
		}
	}
	for(int i=0;i<V;i++){
		cout<<"Vertex "<<i<<" --> Color "<<result[i]<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V=6;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,3);
	addEdge(3,4);
	Color(V);
	return 0;
}
