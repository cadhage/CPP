#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int travllingSalesmanProblem(int graph[][MAX],int  s,int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		if(i!=s){
			v.push_back(i);
		}
	}
	int min_path=INT_MAX;
	do{
		int curr_w=0;
		int k=s;
		for(int i=0;i<v.size();i++){
			curr_w+=graph[k][v[i]];
			k=v[i];
		}
		curr_w+=graph[k][s];
		min_path=min(min_path,curr_w);
	}while(next_permutation(v.begin(),v.end()));
	return min_path;
}
int main() 
{ 
	// matrix representation of graph 
	int graph[][MAX] = { { 0, 10, 15, 20 }, 
					{ 10, 0, 35, 25 }, 
					{ 15, 35, 0, 30 }, 
					{ 20, 25, 30, 0 } }; 
	int s = 0; 
	cout << travllingSalesmanProblem(graph, s,4) << endl; 
	return 0; 
} 

