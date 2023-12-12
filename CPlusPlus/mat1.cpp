/* Driver program to test above functions */
#include <bits/stdc++.h> 
using namespace std;
const int R=4,C=4;
void rotatematrix(int m,int n,int a[][C]){
	int temp[m*n]; 
	int row=0,col=0;
	while(row<m && col<n){
		if(row+1==n || col+1==m)
			break;
		int prev=a[row+1][col];
		for(int i=col;i<n;i++){
			int temp=a[row][i];
			a[row][i]=prev;
			prev=temp;	
		}
		row++;
		for(int i=row;i<m;i++){
			int temp=a[i][n-1];
			a[i][n-1]=prev;
			prev=temp;
		}
		n--;
		if(row<m){
			for(int i=n-1;i>=col;i--){
				int temp=a[m-1][i];
				a[m-1][i]=prev;
				prev=temp;
			}
		}
		m--;
		if(col<n){
			for(int i=m-1;i>=row;i--){
				int temp=a[i][col];
				a[i][col]=prev;
				prev=temp;
			}
		}
		col++;
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
}
int main() 
{ 
    // Test Case 1 
    int a[R][C] = { {1,  2,  3,  4}, 
        {5,  6,  7,  8}, 
        {9,  10, 11, 12}, 
        {13, 14, 15, 16}  }; 
  
    // Tese Case 2 
    /* int a[R][C] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9} 
                     }; 
     */  rotatematrix(4,4, a); 
    return 0; 
}
