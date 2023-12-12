#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
bool isSafe(int a[][MAX],int x,int y,bool v[][MAX],int n){
	return x<n &&y<n&&a[x][y]&&x>=0 &&y>=0&& !v[x][y];
}
void dfs(int a[][MAX],int x,int y,bool v[][MAX],int n){
	v[x][y]=true;
	static int xMoves[]={0,0,1,1,1,-1,-1,-1};
	static int yMoves[]={1,-1,0,-1,1,0,-1,1};
	for(int i=0;i<8;i++){
		if(isSafe(a,x+xMoves[i],y+yMoves[i],v,n)){
			dfs(a,x+xMoves[i],y+yMoves[i],v,n);
		}
	}
}
int countIslands(int a[][MAX],int n){

	int res=0;
	bool v[MAX][MAX];
	memset(v,false,sizeof(v));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] && !v[i][j])
			{
			dfs(a,i,j,v,n);
			res++;
			}
		}
	}
	return res;
}
int main() 
{ 
    int M[][MAX] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M,5); 
}
    
