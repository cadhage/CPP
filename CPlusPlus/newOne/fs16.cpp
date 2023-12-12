#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define V 5
vector<int> parent(100,-1),key(100,INT_MAX);
vector<bool> mstSet(100,false);
int minKey(vector<int> key,vector<bool> mstSet)  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
int printMST(int parent[], int graph[][MAX])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
void printMST(int a[][MAX],int n){
	key[0]=0;
	parent[0]=-1;
	for(int count=0;count<V-1;count++){
		int u=minKey(key,mstSet);
		mstSet[u]=true;
		for(int v=0;v<V;v++){
			if(a[u][v]&& !mstSet[v]){
				if(a[u][v]<key[v]){
					parent[v]=u;
					key[v]=a[u][v];
				}
			}
		}
	}
	printMST(parent,a);
}
int main(){
    int graph[][MAX] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
    primMST(graph);  
	return 0;
}
