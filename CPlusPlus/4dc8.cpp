#include <bits/stdc++.h>
using namespace std;
#define V 4
vector<int> adj[10000];
void addEdge(int x,int y){
	adj[x].push_back(y);
	//adj[y].push_back(x);
}
int minOperations(int x,int y){
	set<int> visit;
	list<pair<int,int>> q;
	pair<int,int> n={x,0};
	q.push_back(n);
	while(!q.empty()){
		auto p=q.front();
		q.pop_front();
		if(p.first==y)
			return p.second;
		visit.insert(p.first);
		if(p.first*2==y||p.first-1==y)
			return p.second+1;
		if(visit.find(p.first*2)==visit.end())
		{
			n.first=p.first*2;
			n.second=p.second+1;
			q.push_back(n);
		}
		if(p.first-1>=0&&visit.find(p.first-1)==visit.end()){
			n.first=p.first-1;
			n.second=p.second+1;
			q.push_back(n);
		}
	}
}
int main() 
{ 
    int x = 4, y = 7; 
    cout << minOperations(x, y); 
    return 0; 
} 
