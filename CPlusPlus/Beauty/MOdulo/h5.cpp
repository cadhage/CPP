#include <bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(vector<int> color) 
{ 
    printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (int i = 0; i < N; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
} 
bool isSafe(vector<int> color,bool a[][N],int v,int c){
	for(int i=0;i<N;i++){
		if(a[v][i] &&c==color[i])
			return false;
	}
	return true;
}
bool graphColoringUtil(vector<int> &color,bool a[][N],int m,int v){
	if(v==N)
		return true;
	for(int i=1;i<=m;i++){
		if(isSafe(color,a,v,i)){
			color[v]=i;
			if(graphColoringUtil(color,a,m,v+1))
				return true;
			color[v]=0;
		}
	}
}
void graphColoring(bool a[][N],int m){
	vector<int> color(N,0);
	if(!graphColoringUtil(color,a,m,0)){
		return;
	}
	else printSolution(color);
}
int main(){
	bool graph[][N] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m = 3; // Number of colors 
    graphColoring (graph, m);
	return 0;
}
