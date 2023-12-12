#include <bits/stdc++.h>
using namespace std;
#define N 8
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
bool isSafe(int x, int y, int sol[N][N]) 
{ 
	return ( x >= 0 && x < N && y >= 0 && 
			y < N && sol[x][y] == 0); 
} 
int sol[100][100]={-1};
void printSolution(int sol[N][N]) 
{ 
	for (int x = 0; x < N; x++) 
	{ 
		for (int y = 0; y < N; y++) 
			printf(" %2d ", sol[x][y]); 
		printf("\n"); 
	} 
} 
int solveKTUtil(int x, int y, int movei, int sol[N][N], 
				int xMove[N], int yMove[N]) 
{ 
	if (movei == N*N) 
		return true; 
	for (int k = 0; k < 8; k++) 
	{ 
		int next_x = x + xMove[k]; 
		int next_y = y + yMove[k]; 
		if (isSafe(next_x, next_y, sol)) 
		{ 
			sol[next_x][next_y] = movei; 
			if (solveKTUtil(next_x, next_y, movei+1, sol, 
							xMove, yMove) == true) 
				return true; 
			sol[next_x][next_y] = 0;
		} 
	} 
	return false; 
} 
int main() 
{ 
	int sol[N][N];
	memset(sol,0,sizeof sol); 
	solveKTUtil(0, 0, 1, sol, xMove, yMove);
	printSolution(sol);  
	return 0; 
} 

