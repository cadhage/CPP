#include <bits/stdc++.h>
using namespace std;
void matrix_chain(int* a,int n,char name,int i,int j){
	if(i==j){
		cout<<name++;
		//name++;
		return;
	}
	cout<<"(";
	matrix_chain(a,name,n,name,i,*((a+i*n)+j));
	matrix_chain(a,name,n,name,*((a+i*n)+i)+1 ,j);
	cout<<")";
}
void matrix_chain_print(int a[],int n){
	int dp[n][n];
	int bracket[n][n];
	for(int i=1;i<n;i++){
		dp[i][i]=0;
	}
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<dp[i][j]){
					dp[i][j]=q;
					bracket[i][j]=k;
				}
			}
		}
	}
	char name='A';
	cout<<"optional Paranthesis";
	cout<<dp[1][n-1];
	matrix_chain((int*)bracket,n,name,1,n-1);
}
int main(){
	int a[]={40,20,30,10,30};
	int n=sizeof(a)/sizeof(a[0]);
	matrix_chain_print(a,n);
	return 0;
}
