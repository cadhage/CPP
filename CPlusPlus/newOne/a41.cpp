#include <bits/stdc++.h>
using namespace std;
void rankify(int a[],int n){
	float R[n]={0};
	for(int i=0;i<n;i++){
		int r=1,s=1;
		for(int j=0;j<n;j++){
			if(j!=i &&a[j]<a[i]){
				r+=1;
			}
			if(j!=i && a[j]==a[i])
				s+=1;
		}
		R[i]=r+(float)(s-1)/(float)2;
	}
	for(int i=0;i<n;i++){
		cout<<R[i]<<' ';
	}
}
int main(){
	int A[] = {1, 2, 5, 2, 1, 25, 2}; 
    int n = sizeof(A) / sizeof(A[0]); 
      
    for (int i = 0; i < n; i++) 
    cout << A[i] << ' '; 
    cout << '\n'; 
      
    rankify(A, n); 
	return 0;
}
