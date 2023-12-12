#include <bits/stdc++.h>
using namespace std;
#define NIL -1
//#define V 3
vector<int> adj[10000];
vector<int> child(10000,0);
void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void APUtil(int u,vector<bool> &v,vector<int> &disc,  
                                      vector<int> &low,vector<int> &parent, vector<bool> &ap,vector<pair<int,int>> &br,int V) 
{  
    child[u]= 0; 
    static int times=0;
    v[u] = true; 
    disc[u] = low[u] = ++times; 
    for (auto it: adj[u]) 
    {  
        if (!v[it]) 
        { 
            child[u]++; 
            parent[it] = u; 
            APUtil(it, v, disc, low, parent, ap,br,V); 
            low[u]  = min(low[u], low[it]); 
            if (low[it] >disc[u])
				br.push_back(make_pair(u,it)); 
			if (parent[u] == NIL && child[u] > 1) 
               ap[u] = true; 
            if (parent[u] != NIL && low[it] >= disc[u]) 
               ap[u] = true; 
        } 
        else if (it != parent[u]) 
            low[u]  = min(low[u], disc[it]); 
    } 
}   
void AP(int V) 
{ 
  	vector<int> disc(V,0),low(V,0),parent(V,NIL);
  	vector<bool> v(V,false),AP(V,false); 
  	vector<pair<int,int>> br(V,{0,0});
  	//int time=0;
    for (int i = 0; i < V; i++) 
        if (v[i] == false) 
            APUtil(i, v, disc, low, parent, AP,br,V);
	int cap=0;
	//sort(AP.begin(),AP.end());
	sort(br.begin(),br.end());
	for (int i = 0; i < V; i++) 
         if (AP[i])
			cap++; 
    cout<<cap<<'\n';
    for (int i = 0; i < V; i++) 
        if (AP[i])
            cout << i << " "; 
    int cbr=0; 
    cout<<'\n';
    for (auto b:br) 
        if(b.first||b.second)
			cbr++;
    cout<<cbr<<'\n';
    for (auto b:br) 
        if(b.first||b.second)
			cout << b.first << " "<<b.second<<'\n'; 
} 
 
int main() 
{  	
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    while(m--){
        int x,y;cin>>x>>y;
        x--;y--;
        addEdge(x,y);
    }
   	AP(n); 
    return 0; 
} 
