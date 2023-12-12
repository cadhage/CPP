#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
#define M 100
int minKey(vector<int> key,vector<bool> mstSet,int V){
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++){
		if(!mstSet[i]&&key[i]<min){
			min=key[i],min_index=i;
		}
	}
	return min_index;
}
void primMST(int a[][M],int V){
	vector<int> parent(V);
	vector<int> key(V,INT_MAX);
	vector<bool> mstSet(V,false);
	key[0]=0,parent[0]=-1;
	for(int i=0;i<V-1;i++){
		int it=minKey(key,mstSet,V);
		mstSet[it]=true;
		for(int j=0;j<V;j++){
			if(a[it][j]&&!mstSet[j] && a[it][j]<key[j]){
				parent[j]=it,key[j]=a[it][j];
			}
		}
	}
	for(int i=1;i<V;i++){
		cout<<parent[i]<<'-'<<i<<'\t'<<a[i][parent[i]]<<'\n';
	}
}
int main()  
{  
	int V=5;
    int graph[][M] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
    primMST(graph,V);  
  
    return 0;  
}  
