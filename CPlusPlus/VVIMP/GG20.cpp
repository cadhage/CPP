#include <bits/stdc++.h>
using namespace std;
#define V 4
bool isBipartite(int a[][V],int i){
	queue<int> q;
	q.push(i);
	vector<int> color(V,-1);
	color[i]=1;
	while(!q.empty()){
		int n=q.front();
		q.pop();
		if(a[n][n]==1)
			return false;
		for(int j=0;j<V;j++){
			if(a[n][j] && color[j]==-1)
			{
				q.push(j);
				color[j]=1-color[n];
			}
			if(a[n][j] && color[n]==color[j])
				return false;
		}
	}
	return true;
}
int main() 
{ 
    int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G, 0) ? cout << "Yes" : cout << "No"; 
    return 0; 
} 
