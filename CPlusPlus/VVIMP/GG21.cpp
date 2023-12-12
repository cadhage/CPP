#include <bits/stdc++.h>
using namespace std;
#define V 4
/* A utility function to print solution */
vector<int> color(1000,0);
bool isSafe(int v,bool a[][V],int c){
	for(int i=0;i<V;i++){
		if(a[v][i]&&c==color[i]){
			return false;
		}
	}
	return true;
}
bool graphColoringUtil(bool a[][V],int m,int i){
	if(i==V)
		return true;
	for(int c=1;c<=m;c++){
		if(isSafe(i,a,c)){
			color[i]=c;
			if(graphColoringUtil(a,m,i+1))
				return true;
			color[i]=0;
		}
	}
	return false;
}
void printSolution() 
{ 
    printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (int i = 0; i < V; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
} 
void graphColoring(bool a[][V],int m){
	for(int i=0;i<V;i++){
		if(!graphColoringUtil(a,m,0)){
			cout<<"Solution Does Not Exits"<<'\n';
			//return false;
		}
	}
	printSolution();
	//return true;	
}
int main(){
    bool graph[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m=3; // Number of colors 
    graphColoring (graph, m); 
    return 0; 
}
