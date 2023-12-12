#include <bits/stdc++.h> 
using namespace std;
#define V 100
vector<int> parent(100,-1),key(100,INT_MAX);
vector<bool> mstSet(100,false);
vector<vector<int>>  graph;
int minKey()  
{  
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
    return min_index;  
}   
void primMST(){ 
	key[0]=0;
	parent[0]=-1;	
	for(int i=0;i<graph[0].size()-1;i++){
		int u=minKey();
		mstSet[u]=true;
		for(int j=0;j<graph[0].size();j++){
			if(graph[i][j]>0 && !mstSet[j] &&
			graph[i][j]<key[j]){
				parent[j]=i;key[j]=graph[i][j];
			}
		}
	}
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i < graph[0].size(); i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";	
}
int main() 
{ 
	graph = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 
	primMST(); 
	return 0; 
} 
