#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	//adj[y].push_back(x);
}

void countPathsUtil(int s,int d,vector<bool> &v,int &pathCount){
	v[s]=true;
	if(s==d)
		pathCount++;
	else{
		for(auto it:adj[s]){
			if(!v[it]){
				countPathsUtil(it,d,v,pathCount);
			}
		}
	}
	v[s]=false;
}
int countPaths(int s,int d){
	vector<bool> v(V,false);
	int pathCount=0;
	countPathsUtil(s,d,v,pathCount);
	return pathCount;
}
int main() 
{ 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(0, 3); 
    addEdge(2, 0); 
    addEdge(2, 1); 
    addEdge(1, 3); 
    int s = 2, d = 3; 
    cout << countPaths(s, d); 
  
    return 0; 
}
