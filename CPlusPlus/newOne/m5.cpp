#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void unique(int a[][MAX],int n,int m){
	int mx=0,flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mx=max(mx,a[i][j]);	
		}
	}
	int b[mx+1]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[a[i][j]]++;
		}
	}
	for(int i=1;i<mx+1;i++){
		if(b[i]==1)
			cout<<i<<' ';
	}
	if(flag==0)
		cout<<"Not Possible";
}
int main(){
	 int mat[][MAX] = {{ 1, 2, 3, 20}, 
                     {5, 6, 20, 25}, 
                     {1, 3, 5, 6}, 
                     {6, 7, 8, 15}}; 
                       
    // function that calculate unique element 
    unique(mat, 4, 4);
	return  0;
}
