// C++ program for Bidirectional BFS search 
// to check path between two vertices 
#include <bits/stdc++.h> 
using namespace std; 
  
// class representing undirected graph 
// using adjacency list 
class Graph 
{ 
    //number of nodes in graph 
    int V; 
  
    // Adjacency list 
    
public: 
	list<int> *adj; 
    Graph(int V); 
    int isIntersecting(bool *s_visited, bool *t_visited); 
    void addEdge(int u, int v); 
    void printPath(int *s_parent, int *t_parent, int s, 
                             int t, int intersectNode); 
    void BFS(list<int> *queue, bool *visited, int *parent); 
    int biDirSearch(int s, int t);
	int biDirSearch(int s); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
}; 
  
// Method for adding undirected edge 
void Graph::addEdge(int u, int v) 
{ 
    this->adj[u].push_back(v); 
    this->adj[v].push_back(u); 
}; 
  
// Method for Breadth First Search 
void Graph::BFS(list<int> *queue, bool *visited, 
                                    int *parent) 
{ 
    int current = queue->front(); 
    queue->pop_front(); 
    list<int>::iterator i; 
    for (i=adj[current].begin();i != adj[current].end();i++) 
    { 
        // If adjacent vertex is not visited earlier 
        // mark it visited by assigning true value 
        if (!visited[*i]) 
        { 
            // set current as parent of this vertex 
            parent[*i] = current; 
  
            // Mark this vertex visited 
            visited[*i] = true; 
  
            // Push to the end of queue 
            queue->push_back(*i); 
        } 
    } 
}; 
  
// check for intersecting vertex 
int Graph::isIntersecting(bool *s_visited, bool *t_visited) 
{ 
    int intersectNode = -1; 
    for(int i=0;i<V;i++) 
    { 
        // if a vertex is visited by both front 
        // and back BFS search return that node 
        // else return -1 
        if(s_visited[i] && t_visited[i]) 
            return i; 
    } 
    return -1; 
}; 
  
// Print the path from source to target 
void Graph::printPath(int *s_parent, int *t_parent, 
                  int s, int t, int intersectNode) 
{ 
    vector<int> path; 
    path.push_back(intersectNode); 
    int i = intersectNode; 
    while (i != s) 
    { 
        path.push_back(s_parent[i]); 
        i = s_parent[i]; 
    } 
    reverse(path.begin(), path.end()); 
    i = intersectNode; 
    while(i != t) 
    { 
        path.push_back(t_parent[i]); 
        i = t_parent[i]; 
    } 
  
    vector<int>::iterator it; 
    cout<<"*****Path*****\n"; 
    for(it = path.begin();it != path.end();it++) 
        cout<<*it<<" "; 
    cout<<"\n"; 
}; 
  
// Method for bidirectional searching 
int Graph::biDirSearch(int s, int t) 
{
	
    // boolean array for BFS started from 
    // source and target(front and backward BFS) 
    // for keeping track on visited nodes 
    bool s_visited[V], t_visited[V]; 
  
    // Keep track on parents of nodes 
    // for front and backward search 
    int s_parent[V], t_parent[V]; 
  
    // queue for front and backward search 
    list<int> s_queue, t_queue; 
  
    int intersectNode = -1; 
  
    // necessary initialization 
    for(int i=0; i<V; i++) 
    { 
        s_visited[i] = false; 
        t_visited[i] = false; 
    } 
  
    s_queue.push_back(s); 
    s_visited[s] = true; 
  
    // parent of source is set to -1 
    s_parent[s]=-1; 
  
    t_queue.push_back(t); 
    t_visited[t] = true; 
  
    // parent of target is set to -1 
    t_parent[t] = -1; 
  
    while (!s_queue.empty() && !t_queue.empty()) 
    { 
        // Do BFS from source and target vertices 
        BFS(&s_queue, s_visited, s_parent); 
        BFS(&t_queue, t_visited, t_parent); 
  
        // check for intersecting vertex 
        intersectNode = isIntersecting(s_visited, t_visited); 
  
        // If intersecting vertex is found 
        // that means there exist a path 
        if(intersectNode != -1) 
        { 
            cout << "Path exist between " << s << " and "
                 << t << "\n"; 
            cout << "Intersection at: " << intersectNode << "\n"; 
  
            // print the path and exit the program 
            printPath(s_parent, t_parent, s, t, intersectNode); 
            exit(0); 
        } 
    } 
    return -1; 
} 
int Graph::biDirSearch(int n){
	int a=Graph::biDirSearch(0,n);
	Graph::adj->clear();
	return a;
} 
// Driver code 
int main() 
{ 
//    // no of vertices in graph 
//    int n=15; 
//  
//    // source vertex 
//    int s=0; 
//  
//    // target vertex 
//    int t=14; 
 	int q;cin>>q;
 	for(int iq=0;iq<q;iq++){
  		int n,m;cin>>n>>m;
  		Graph g(n); 
		int a=0,b=0;
		for(int i=0;i<m;i++){
		cin>>a>>b;
		g.addEdge(a-1, b-1); 
		}
		if (g.biDirSearch(n-1) == -1) 
        cout << "Path don't exist between "
        << 0<< " and " << n-1 << "\n";
	}
    return 0;
	 }
