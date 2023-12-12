#include <bits/stdc++.h> 
using namespace std; 
void merge(int a[], int l, int m, int r) 
{ 
	int n1=m-l+1;
	int n2=r-m;
	int R[n2],L[n1];
	for(int i=0;i<n1;i++)
		L[i]=a[l+i];
	for(int i=0;i<n2;i++){
		R[i]=a[m+i+1];
	}
	int j=0,i=0,k=l;
	while(i<n1 && j<n2){
		if(R[j]>=L[i]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;k++;
	}
} 
void mergeSort(int a[], int l, int r) 
{ 
   if(l<r){
   		int m=(l+r)>>1;
   		mergeSort(a,l,m);
   		mergeSort(a,m+1,r);
   		merge(a,l,m,r);
   }
} 
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	mergeSort(arr,0, n-1); 
	cout << "Sorted array: \n"; 
	for(auto it:arr){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

