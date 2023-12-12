#include <bits/stdc++.h>
using namespace std;
const int MAX=1000;
vector<int> adj[1000],v(1000,0),level(1000,-1);
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
int bfs(int s,int  d){
	if(s==d)
		return 0;
	v[s]=1;
	level[s]=0;
	list<int> q;
	q.push_back(s);
	while(!q.empty()){
		int i=q.front();
		q.pop_front();
		for(auto it:adj[i]){
			if(!v[it]){
				q.push_back(it);
				level[it]=level[i]+1;
				v[it]=true;
			}
		}
	}
	return level[d];
}
bool isSafe(int i,int j,int n,int a[][MAX]){
	return (i>=0&&j>=0&&i<n&&j<n&&a[i][j]!=0);
}
int minPath(int a[][MAX],int n){
	int s,d;
	int k=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				if(isSafe(i,j+1,n,a))
					addEdge(k,k+1);
				if(isSafe(i,j-1,n,a))
					addEdge(k,k-1);
				if(isSafe(i+1,j,n,a))
					addEdge(k,k+n);
				if(isSafe(i-1,j,n,a))
					addEdge(k,k-n);
			}
			if(a[i][j]==1)
				s=k;
			if(a[i][j]==2)
				d=k;
			k++;
		}
	}
	return bfs(s,d);
}
int main() 
{ 
    int M[][MAX] = {{ 3 , 3 , 1 , 0 }, 
        { 3 , 0 , 3 , 3 }, 
        { 2 , 3 , 0 , 3 }, 
        { 0 , 3 , 3 , 3 } 
    }; 
  
    cout << minPath(M,4)<< endl; 
  
    return 0; 
}
