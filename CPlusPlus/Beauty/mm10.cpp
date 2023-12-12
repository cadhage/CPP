#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
vector<int> adj[1000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void DFS_Util(int i,vector<int> &v,int vDegree[],int k,int V){
	
}
void k_Core_Graph(int k,int V){
	vector<bool> v(V,false);
	vector<bool> processed(V,false);
	int mindeg=INT_MAX;
	int startVertex;
	vector<int> vDegree(V);
	for(int i=0;i<V;i++){
		vDegree[i]=adj[i].size();
		if(vDegree[i]<mindeg){
			mindeg=vDegree[i];
			startVertex=i;
		}
	}
	DFS_Util(startVertex,v,vDegree,k,V);
	for(int i=0;i<V;i++){
		if(!v[i]){
			DFS_Util(i,v,vDegree,k,V)
		}
	}
	cout<<"K-Core : \n";
	for(int i=0;i<V;i++){
		if(vDegree[i]>=k){
			cout<<"\n["<<v<<"]";
			for(auto it:adj[i]){
				if(vDegree[it]>=k){
					cout<<"->"<<it;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V=6,k=3;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,5);
	addEdge(2,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(2,6);
	addEdge(3,4);
	addEdge(3,6);
	addEdge(3,7);
	addEdge(4,6);
	addEdge(4,7);
	addEdge(5,6);
	addEdge(5,8);
	addEdge(6,7);
	addEdge(6,8);
	k_Core_Graph(k,V);
	return 0;
}
