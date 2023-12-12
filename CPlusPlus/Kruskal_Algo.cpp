#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
void addEdges(vector<pair<int,int>> adj[],int u,int v,int weight){
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}
void prims(vector<pair<int,int>> adj[],int V){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source 
    vector<int> key(V+1, INF); 
    vector<int> parent(V+1, -1); 
    vector<bool> inMST(V+1, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    int sum=0;
    while (!pq.empty()) 
    {
    	int w = pq.top().first;
          int u = pq.top().second; 
        pq.pop(); 
  		cout<<w<<' ';
        inMST[u] = true;
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            //sum+=weight;
            cout<<weight<<' ';
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
                cout<<key[v]<<" ";
            } 
        } 
    } 
//    for (int i = 1; i <= V; ++i) 
//        printf("%d - %d\n", parent[i], i,key[i]);
	cout<<sum; 
}
int main(){
	//int V=9;
	//vector<pair<int ,int>> adj[V];
	int nodes,edges;
	long long weight, minimumCost;
    cin >> nodes >> edges;
    vector<pair<int ,int>> adj[nodes+1];
    for(int i = 0;i < edges;++i)
    {
        int x,y;cin >> x >> y >> weight;
        addEdges(adj,x,y,weight);
    }
	prims(adj,nodes);
	return 0;
}
