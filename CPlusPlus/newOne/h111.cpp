#include<bits/stdc++.h>
using namespace std; 
#define MAX 100
void diagonalsquare(int mat[MAX][MAX], int row, int column) 
{ 
	cout << " \nDiagonal one : "; 
	for (int i = 0; i < row; i++) 
	{ 
		cout << mat[i][i] * mat[i][i] << " "; 
	} 
	cout << " \n\nDiagonal two : "; 
	for (int i = 0; i < row; i++) 
	{ 
		cout<<mat[i][row-i-1]*mat[i][row-i-1]<<' ';
	} 
} 
int main() 
{ 
	int mat[][MAX] = { { 2, 5, 7 }, 
					{ 3, 7, 2 }, 
					{ 5, 6, 9 } }; 
	diagonalsquare(mat, 3, 3); 
	return 0; 
} 

