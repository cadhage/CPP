#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
const int MAX=100;
vector<bool> v(10000,0),rec(10000,0);
void dfs(int i){
	v[i]=1;
	for(auto it:graph[i]){
		if(!v[it]){
			dfs(it);
		}
	}
}
void solver(int n){
	int res=0;
	for(int i=0;i<n;i++){
		//dfs(i);//cout<<i<<" "<<level[i]<<'\n';
		if(!v[i]){
			dfs(i);
			res++;
		}
	}
	cout<<res<<'\n';
}
int main() 
{ 
  
    graph[0].push_back(1); 
    graph[0].push_back(2); 
//    graph[1].push_back(3); 
    graph[3].push_back(4); 
    solver(5);
    return 0; 
}
