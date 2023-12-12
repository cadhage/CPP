#include <stdio.h>  
#define N 4 
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]); 
void printSolution(int sol[N][N]) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", sol[i][j]); 
		printf("\n"); 
	} 
} 
bool isSafe(int maze[N][N], int x, int y) 
{ 
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != 0) 
		return true; 

	return false; 
} 
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) 
{ 
	if(x==N-1 && y==N-1)
	{
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y)){
		sol[x][y]=1;
		for(int i=1;i<=maze[x][y] && i<N;i++){
			if(solveMazeUtil(maze,x+i,y,sol))
				return true;
			if(solveMazeUtil(maze,x,y+i ,sol))
				return true;
		}
		sol[x][y]=0;
	//	return false;
	}
	return false;
} 
int main() 
{ 
  int maze[N][N] = { { 2, 1, 0, 0 }, 
                       { 3, 0, 0, 1 }, 
                       { 0, 1, 0, 1 }, 
                       { 0, 0, 0, 1 } }; 
	int sol[N][N] = { { 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 } }; 
	if (solveMazeUtil(maze, 0, 0, sol) == false) { 
		printf("Solution doesn't exist"); 
	} 
	printSolution(sol); 
	return 0; 
} 

