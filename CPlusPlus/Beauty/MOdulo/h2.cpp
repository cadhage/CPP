#include <bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int a[],int n){
	int dp[n][n];
	for(int i=0;i<n;i++){
			dp[i][i]=0;
	}
	for(int L=2;L<n;L++){
		for(int i=0;i<n-L+1;i++){
			int j=i+L-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int d=dp[i][k]+dp[k+1][j]+
					a[i]*a[k]*a[j];
				if(d<dp[i][j])
					dp[i][j]=d;
			}
			
		}
	}
	return dp[0][n-1];
}
int main() 
{ 
    int arr[] = {1, 2, 3, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n); 
}
