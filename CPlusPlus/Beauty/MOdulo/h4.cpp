#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define N 4
bool isSafe(int x,int y,int sol[][N]){
	return (x>=0 && x<N && y>=0&&y<N&&sol[x][y]==1);
}
void printSolution(int sol[][N]){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			cout<<sol[x][y]<<' ';
		}
		cout<<'\n';
	}
}
int solveMazeUtil(int maze[][N],int x,int y,int sol[N][N]){
	if(x==N-1&&y==N-1){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(x,y,maze)){
		sol[x][y]=1;
		if(solveMazeUtil(maze,x+1,y,sol))
			return true;
		if(solveMazeUtil(maze,x,y+1,sol))
			return true;
		sol[x][y]=0;
		return false;
	}
	return false;
}
bool solveMaze(int a[][N]){
	int sol[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j]=0;
		}
	}
	if(!solveMazeUtil(a,0,0,sol)){
		cout<<"Doest exit";
		return false;
	}
	printSolution(sol);
	return true;
}

int main(){
	int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze);
	return 0;
}
