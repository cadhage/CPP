#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void spiralPrint(int a[][MAX],int n,int m){
	int r=0,c=0;
	while(r<n && c<m){
		for(int i=c;i<m;i++){
			cout<<a[r][i]<<' ';	
		}
		r++;
		for(int i=r;i<n;i++){
			cout<<a[i][m-1]<<' ';
		}
		m--;
		if(r<n){
			for(int i=m-1;i>=c;i--){
				cout<<a[n-1][i]<<" ";
			}
			n--;
		}
		if(c<m){
			for(int i=n-1;i>=r;i--){
				cout<<a[i][c]<<" ";
			}
			c++;
		}
	}
}
int main(){
	  int a[][MAX] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 
  
    spiralPrint(a,3,6); 
	return 0;
}
