#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
void productPuzzle(int a[],int n){
	long double sum=0;
	for(int i=0;i<n;i++){
		sum+=(long double) log10(a[i]);
		cout<<sum<<' ';
	}
	for(int i=0;i<n;i++){
		cout<<(int)(EPS+pow((long double)10.00,sum-log10(a[i])))<<' ';
	}
} 
int main(){

    int a[] = { 10, 3, 5, 6, 2 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout << "The product array is: \n"; 
    productPuzzle(a, n); 
    return 0; 
} 
