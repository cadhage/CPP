#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int matrixChain(int a[],int i,int j){
	if(i==j)
		return 0;
	int max=INT_MAX;
	int count=0;
	for(int k=i;k<j;k++){
		count=matrixChain(a,i,k)+matrixChain(a,k+1,j)+a[i-1]*a[k]*a[j];
		if(count<max)
		max=count;
	}
	return max;
}
int main(){
	int a[]={1, 2, 3, 4, 3}; 
	int n=sizeof(a)/sizeof(a[0]);
	cout<<matrixChain(a,1,n-1);
	return 0;
}
