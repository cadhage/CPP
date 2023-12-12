#include <bits/stdc++.h> 
using namespace std;  
#define V 5    
void printSolution();  
vector<int> path(1000,0);
bool isSafe(int v, bool graph[V][V],int pos)  
{  
    if (graph [path[pos - 1]][ v ] == 0)  
        return false;  
    for (int i = 0; i < pos; i++)  
        if (path[i] == v)  
            return false;  
  
    return true;  
}  
bool hamCycleUtil(bool graph[V][V],int pos)  
{  
    if (pos == V)  
    {  
        if (graph[path[pos - 1]][path[0]] == 1)  
            return true;  
        else
            return false;  
    }  
    for (int v = 1; v < V; v++)  
    {  
        if (isSafe(v, graph, pos))  
        {  
            path[pos] = v;  
            if (hamCycleUtil (graph,pos + 1) == true)  
                return true;  
            path[pos] = -1;  
        }  
    }  
    return false;  
}  
void printSolution()  
{  
    cout << "Solution Exists: \n";  
    for (int i = 0; i < V; i++)  
        cout << path[i] << " ";  
    cout << path[0] << " ";  
    cout << endl; 
}  
 
int main()  
{  
    bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}}; 
	path[0] = 0;
	string s="";
    s=hamCycleUtil(graph1, 1)?"Yes":"No";  
    if(s=="Yes")
		printSolution();  
	else cout<<"Solution Doesnt Exit"<<'\n';  
    return 0;  
}  
