#include <bits/stdc++.h>
using namespace std;
void leftRotateUtil(int a[],int n){
	int temp=a[0];
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1];
	}
	a[n-1]=temp;
}
void leftRotation(int a[],int d,int n){
	for(int i=0;i<d;i++){
		leftRotateUtil(a,n);
	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    leftRotation(arr, 2, n); 
    for(int i=0;i<n;i++)
    	cout<<arr[i]<<' ';
	return 0;
}
