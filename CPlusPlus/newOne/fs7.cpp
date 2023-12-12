#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 4 				
void setZeros(int matrix[][C]) {
	int row[R]={0};
	int col[C]={0};
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(matrix[i][j]==1){
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(row[i]||col[j]){
				matrix[i][j]=1;
			}
		}
	}
}	
void printMatrix(int mat[R][C]) 
{ 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            cout << mat[i][j]; 
        } 
        cout << "\n"; 
    } 
} 
	
int main() {
	int mat[R][C] = { { 1, 0, 0, 1 }, 
                      { 0, 0, 1, 0 }, 
                      { 0, 0, 0, 0 } }; 
  
    cout << "Input Matrix :\n"; 
    printMatrix(mat); 
	setZeros(mat);
    cout << "Matrix After Modification :\n"; 
    printMatrix(mat); 
}

