#include <bits/stdc++.h>
using namespace std;
#define INTF INT_MIN
void dfs(vector<pair<int,int>> adj[],int  i,vector<int> &v,stack<int> &st){
	v[i]=1;
	for(pair<int,int> it:adj[i]){
		if(v[it.first]==0){
			//curr=prev+it.second;
			dfs(adj,it.first,v,st);
		}
	}
	st.push(i);
}
int longestCable(vector<pair<int,int>> graph[], int n){
	vector<int> v(n+1,0);
	stack<int> st;
	for(int i=1;i<=n;i++){
		if(v[i]==0)
		dfs(graph,i,v,st);
	}
	vector<int> dist(n+1,INTF);  
    dist[0]=dist[1] = 0;   
    while (!st.empty()) {   
        int u = st.top();  
        st.pop();   
        if (dist[u] != INTF) {  
            for (auto it:graph[u])  
                if (dist[it.first] < dist[u] + it.second) 
                    dist[it.first] = dist[u] + it.second;  
        }  
    }  
    
    // Print the calculated longest distances  
    for (int i = 0; i <n+1; i++)  
        (dist[i] == INTF) ? cout << "INF " : cout << dist[i] << " "; 
      
    v.clear(); 
	
}
int main() 
{ 
    // n is number of cities 
    int n = 6; 
  
    vector< pair<int,int> > graph[n+1]; 
  
    // create undirected graph 
    // first edge 
    graph[1].push_back(make_pair(2, 3)); 
    graph[2].push_back(make_pair(1, 3)); 
  
    // second edge 
    graph[2].push_back(make_pair(3, 4)); 
    graph[3].push_back(make_pair(2, 4)); 
  
    // third edge 
    graph[2].push_back(make_pair(6, 2)); 
    graph[6].push_back(make_pair(2, 2)); 
  
    // fourth edge 
    graph[4].push_back(make_pair(6, 6)); 
    graph[6].push_back(make_pair(4, 6)); 
  
    // fifth edge 
    graph[5].push_back(make_pair(6, 5)); 
    graph[6].push_back(make_pair(5, 5)); 
  
    cout << "Maximum length of cable = "
         << longestCable(graph, n); 
  
    return 0; 
} 
