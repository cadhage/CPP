#include <bits/stdc++.h>
using namespace std;
#define V 4
bool isBipartite(int adj[][V],int i){
	list<int> q;
	vector<int> color(V,-1);
	color[i]=1;
	q.push_back(i);
	while(!q.empty()){
		i=q.front();
		q.pop_front();
		///q.pop();
		if(adj[i][i]==1)
			return false;
		for(int j=0;j<V;j++){
			if(adj[i][j] && color[j]==-1){
				color[j]=1-color[i];
				q.push_back(j);
			}
			else if(adj[i][j] &&color[i]==color[j])
				return false;
		}
	}
	return true;
}
int main(){
	int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G, 0) ? cout << "Yes" : cout << "No"; 
	return 0;
}
