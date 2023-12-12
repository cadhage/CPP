#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void maxelement(int n,int mat[][MAX]){
	int mx=0;
	int result[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]>mx)
				mx=mat[i][j];
		}
		result[i]=mx;
		mx=0;
	}
	for(int i=0;i<n;i++)
		cout<<result[i]<<' ';
}
int main(){
	int arr[][MAX] = { {3, 4, 1, 8}, 
                        {1, 4, 9, 11}, 
                        {76, 34, 21, 1}, 
                        {2, 1, 4, 5} }; 
    // Calling the function  
        maxelement(4, arr);
	return 0;
}
