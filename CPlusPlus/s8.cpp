#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
#define V 5
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void greedyColoring(){
	vector<int> result(V,-1);
	result[0]=0;
	vector<bool> available(V,false);
	for(int i=1;i<V;i++){
		for(auto it:adj[i]){
			if(result[it]!=-1){
				available[result[it]]=true;
			}
		}
		int cr;
		for(cr=0;cr<V;cr++){
			if(!available[cr])
				break;
		}
		result[i]=cr;
		for(auto it:adj[i]){
			if(result[it]!=-1){
				available[result[it]]=false;
			}
		}
	}
	for(int i=0;i<V;i++){
		cout<<"Vertex "<<i<<"--> cloring  "<<result[i]<<'\n';
	}
}
int main(){
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,3);
	addEdge(3,4);
	greedyColoring();	
}
