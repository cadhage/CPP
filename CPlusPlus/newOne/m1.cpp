#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void rotatematrix(int m,int n,int mat[MAX][MAX]){
	int row=0,col=0;
	int R=m,C=n;
	int prev,curr;
	while(row<m && col<n){
		if(row==m-1 ||col==n-1){
			break;
		}
		prev=mat[row+1][col];
		for(int i=col;i<n;i++){
			curr=mat[row][i];
			mat[row][i]=prev;
			prev=curr;
		}
		for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
	cout<<"----------------\n";
		row++;
		/* Move elements of last column from the remaining columns */
		for (int i = row; i < m; i++) 
		{ 
			curr = mat[i][n-1]; 
			mat[i][n-1] = prev; 
			prev = curr; 
		} 
		n--; 
		for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
	cout<<"----------------\n";
		/* Move elements of last row from the remaining rows */
		if (row < m) 
		{ 
			for (int i = n-1; i >= col; i--) 
			{ 
				curr = mat[m-1][i]; 
				mat[m-1][i] = prev; 
				prev = curr; 
			} 
		} 
		m--; 
		for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
	cout<<"----------------\n";
		/* Move elements of first column from the remaining rows */
		if (col < n) 
		{ 
			for (int i = m-1; i >= row; i--) 
			{ 
				curr = mat[i][col]; 
				mat[i][col] = prev; 
				prev = curr; 
			} 
		} 
		col++; 
	}
			for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
	cout<<"----------------"<<'\n';
	for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
} 
int main() 
{  
	int R=4,C=4;
    int a[][MAX]= { {1,  2,  3,  4}, 
        {5,  6,  7,  8}, 
        {9,  10, 11, 12}, 
        {13, 14, 15, 16}  }; 
     rotatematrix(R, C, a); 
    return 0; 
} 
