#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void spiralPrint(int R,int C,int a[MAX][MAX]){
	int m=R,n=C;
	int k=0,l=0;
	while(k<m&&l<n){
		for(int i=l;i<n;i++){
			cout<<a[k][i]<<" ";
		}
		k++;
		for(int i=k;i<m;i++){
			cout<<a[i][n-1]<<" ";
		}
		n--;
		if(k<m){
			for(int i=n-1;i>=l;i--){
				cout<<a[m-1][i]<<' ';
			}
			m--;
		}
		if(l<n){
			for(int i=m-1;i>=k;i--){
				cout<<a[i][l]<<' ';
			}
			l++;
		}
	}
}
int main(){
	int R=3,C=6;
	int a[][MAX] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 
  
    spiralPrint(R, C, a); 
	return 0;
}
