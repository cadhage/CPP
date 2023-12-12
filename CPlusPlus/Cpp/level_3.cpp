#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
const int MAX=100;
vector<bool> v(10000,0),rec(10000,0);
void solver(int n){
	list<int> q;
	q.push_back(0);
	int level[n]={0};
	v[0]=0;
	level[0]=0;
	while(!q.empty()){
		int r=q.front();
		q.pop_front();
		for(auto it:graph[r]){
			if(!v[it]){
				q.push_back(it);
				v[it]=1;
				level[it]=level[r]+1;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<i<<" "<<level[i]<<'\n';
	}
}
int main() 
{ 
  
    graph[0].push_back(1); 
    graph[0].push_back(2); 
    graph[1].push_back(3); 
    graph[1].push_back(4); 
    graph[1].push_back(5); 
    graph[2].push_back(5); 
    graph[2].push_back(6); 
    graph[6].push_back(7); 
    solver(8);
    return 0; 
}
