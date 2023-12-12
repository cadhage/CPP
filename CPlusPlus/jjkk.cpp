#include <bits/stdc++.h>
using namespace std;
void printParanthesis(int i,int j,int n,int *brack,char &name){
	if(i==j){
		cout<<name++;
		return;
	}
	cout<<"(";
	printParanthesis(i,*((brack+i*n)+j),n,brack,name);
	printParanthesis(*((brack+i*n)+j)+1,j,n,brack,name);
	cout<<")";
	
}
int MatrixChainOrder(int a[],int s,int e){
	int dp[e][e];
	for(int i=1;i<=e;i++){
		dp[i][i]=0;
	}
	int min=INT_MAX;
	int brack[e][e];
	for(int l=2;l<e;l++){
		for(int i=1;i<e-l+1;i++){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<dp[i][j]){
					dp[i][j]=q;
					brack[i][j]=k;	
				}
			}
		}
	}
	char name='A';
	printParanthesis(1,e-1,e,(int*)brack,name);
	return dp[1][e-1];
}
int main(){
	  int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 0, n); 
}
