#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define V 12
vector<int> adj[10000];
vector<int> child(10000,0);

void addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
int c=0;
void BCCUtil(int u,vector<int> &disc,  
    vector<int> &low,vector<int> &parent,list<pair<int,int>> &st) 
{  
    child[u]= 0; 
    static int times=0,ci=0;
    disc[u] = low[u] = ++times; 
    for (auto it: adj[u]) 
    {  
        if (disc[it]==-1) 
        { 
            child[u]++; 
            parent[it] = u; 
            st.push_back({u,it});
            BCCUtil(it,disc, low, parent,st); 
            low[u]  = min(low[u], low[it]);  
			if ((disc[u] == NIL && child[u] > 1) || (disc[u] != NIL && low[it] >= disc[u])){
                while (st.back().first != u || st.back().second != it) { 
                    //cout <<st.back().first << "--" <<st.back().second  << " "; 
                    ci++;
					st.pop_back(); 
                } 
                ci++;
               // cout <<st.back().first << "--" << st.back().second ; 
                st.pop_back(); 
                cout << endl; 
                c++;
			}
			cout<<ci<<'\n';  
        } 
        else if (it != parent[u]) {
            low[u]  = min(low[u], disc[it]); 
                   if (disc[it] < disc[u]) { 
                st.push_back(make_pair(u, it)); 
            }
		}
    } 
}   
void BCC() 
{ 
  	vector<int> disc(V,NIL),low(V,NIL),parent(V,NIL);
  	list<pair<int,int>> st;
    for (int i = 0; i < V; i++){
        if (disc[i]==NIL) 
            BCCUtil(i,disc, low, parent,st);
    	int j = 0,ci=0; 
        while (!st.empty()) { 
            j = 1; 
            ci++;
            //cout <<st.back().first << "--" <<st.back().second  << " "; 
            st.pop_back(); 
        }
		cout<<ci<<'\n'; 
        if (j == 1) { 
            cout <<endl; 
            c++; 
        } 
    } 
} 
 
int main() 
{  	
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    addEdge(0, 1); 
    addEdge(1, 0); 
    addEdge(1, 2); 
    addEdge(2, 1); 
    addEdge(1, 3); 
    addEdge(3, 1); 
    addEdge(2, 3); 
    addEdge(3, 2); 
    addEdge(2, 4); 
    addEdge(4, 2); 
    addEdge(3, 4); 
    addEdge(4, 3); 
    addEdge(1, 5); 
    addEdge(5, 1); 
    addEdge(0, 6); 
    addEdge(6, 0); 
    addEdge(5, 6); 
    addEdge(6, 5); 
    addEdge(5, 7); 
    addEdge(7, 5); 
    addEdge(5, 8); 
    addEdge(8, 5); 
    addEdge(7, 8); 
    addEdge(8, 7); 
    addEdge(8, 9); 
    addEdge(9, 8); 
    addEdge(10, 11); 
    addEdge(11, 10);
   	BCC(); 
  
    return 0; 
} 
