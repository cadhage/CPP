#include <bits/stdc++.h>
using namespace std;
#define V 5
void printSolution(vector<int> path)  
{  
    cout << "Solution Exists:\n";  
    for (int i = 0; i < V; i++)  
        cout << path[i] << " ";   
    cout << path[0] << " ";  
}
bool isSafe(int v, bool graph[V][V],  
            vector<int> &path, int pos)  
{  
    if (graph [path[pos - 1]][ v ] == 0)  
        return false;  
    for (int i = 0; i < pos; i++)  
        if (path[i] == v)  
            return false;  
  
    return true;  
}  
bool hamCycle(bool a[][V],vector<int> &path,int index){
	if (index== V)  
    {  
        if (a[path[index - 1]][path[0]] == 1)  
            return true;  
        else
            return false;  
    }  
	for(int i=1;i<V;i++)
	{
		if(isSafe(i,a,path,index)){
			path[index]=i;
			if(hamCycle(a,path,index+1))
				return true;
			path[index]=0;
		}
	}
	return false;
}
int main(){
	 bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
	vector<int> path(V,0); 
    hamCycle(graph1,path,1); 
    printSolution(path);
	 
}
