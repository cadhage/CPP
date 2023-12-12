#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int  countIslands(int a[MAX][MAX],int n,int m){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='X'){
				if((i==0 ||a[i-1][j]=='O')&&
					(j==0 ||a[i][j-1]=='O')){
						count++;
					}
			}
		}
	}
	return count;
}
int main() 
{ 
    int mat[][MAX] =  {{'O', 'O', 'O'}, 
                      {'X', 'X', 'O'}, 
                      {'X', 'X', 'O'}, 
                      {'O', 'O', 'X'}, 
                      {'O', 'O', 'X'}, 
                      {'X', 'X', 'O'} 
                    }; 
    cout << "Number of rectangular islands is "
         << countIslands(mat,6,3); 
    return 0; 
}
