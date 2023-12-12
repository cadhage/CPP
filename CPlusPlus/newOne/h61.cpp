#include <bits/stdc++.h> 
using namespace std; 
void heapify(int a[],int n,int i){
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[large]){
		large=l;
	}
	if(r<n&&a[r]>a[large])
		large=r;
	if(large!=i){
		swap(a[i],a[large]);
		heapify(a,n,large);
	}
}
void heapSort(int a[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	heapSort(arr, n); 
	cout << "Sorted array: \n"; 
	for(auto it:arr){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

