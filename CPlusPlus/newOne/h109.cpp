#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000
int first(bool arr[], int low, int high)  
{  
    for(int i=0;i<high;i++){
    	if(arr[i]==1){
    		return i;
		}
	} 
    return -1;  
}  
int rowWithMax1s(bool mat[MAX][MAX],int n){
	int max=0;
	int j=first(mat[0],0,n);
	if(j==-1)
		j=n-1;
	for(int i=1;i<n;i++){
		while(j>=0 &&mat[i][j]==1){
			j--;
			max=i;
		}
	}
	return max;
}
int main()  
{  
    bool mat[MAX][MAX] = { {0, 0, 0, 1},  
                    {0, 1, 1, 1},  
                    {1, 1, 1, 1},  
                    {0, 0, 0, 0}};  
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat,4);  
    return 0;  
}  
  
